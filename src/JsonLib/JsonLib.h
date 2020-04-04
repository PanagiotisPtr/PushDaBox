#ifndef JSONLIB_H
#define JSONLIB_H

#include <iostream>
#include <cctype>
#include <unordered_map>
#include <sstream>
#include <memory>
#include <type_traits>
#include <iterator>

namespace JsonLib {

struct InvalidKeyException : public std::exception {
    const char* what () const throw () {
        return "Could not find key in node.";
    }
};

struct ExistingKeyException : public std::exception {
    const char* what () const throw () {
        return "Node already exists in JSON Object.";
    }
};

class JsonValue {
public:
    using KeyType = std::string;

    JsonValue() {}

    template<typename ValueType>
    JsonValue(ValueType v) {
        this->setValue(v);
    }

    virtual const JsonValue& operator[](KeyType k) const {
        return *this;
    }

    virtual std::string getValue() const { return this->value; }

    template<typename ValueType>
    void setValue(ValueType v) {
        std::stringstream ss;
        ss << v;
        this->value = ss.str();
    }

    virtual std::string serialise() const {
        if (isNumber(this->value)) {
            return this->value;
        }
        std::stringstream ss;
        ss << '"' << this->value << '"';
        return ss.str();
    }

    virtual void deserialise(const std::string str, size_t& pos) {
        this->value = this->readString(str, pos);
    }

protected:
    std::string readString(const std::string& str, size_t& pos) {
        std::string rv = "";
        if (str[pos] == '"') pos++;
        while (str[pos] != '"' && str[pos] != ',') rv.push_back(str[pos++]);
        if (str[pos] == '"') pos++;
        
        return rv;
    }

private:
    std::string value;

    bool isNumber(const std::string& str) const {
        for (auto c : str) {
            if (c != '.' && (c < '0' || c > '9')) {
                return false;
            }
        }
        return true;
    }
};

class JsonObject : public JsonValue {
public:
    using ValuePointer = std::shared_ptr<JsonValue>;

    JsonObject() {}

    const JsonValue& operator[](KeyType k) const override {
        if (this->values.find(k) == std::end(this->values)) {
            throw InvalidKeyException();
        }

        return *this->values.at(k).get();
    }

    void addValue(KeyType k, ValuePointer v) {
        if (this->values.find(k) != std::end(this->values)) {
            throw ExistingKeyException();
        }

        this->values.insert({k, v});
    }

    template<typename JsonNodeType,
             std::enable_if_t<
                std::is_same<JsonNodeType, JsonObject>::value ||
                std::is_same<JsonNodeType, JsonValue>::value, int> = 0>
    void addValue(KeyType k, JsonNodeType v) {
        this->addValue(k, std::make_shared<JsonNodeType>(std::move(v)));
    }

    template<typename ValueType,
             std::enable_if_t<
                std::is_integral<ValueType>::value ||
                std::is_same<ValueType, const char*>::value ||
                std::is_same<ValueType, std::string>::value, int> = 0>
    void addValue(KeyType k, ValueType v) {
        if (this->values.find(k) != std::end(this->values)) {
            throw ExistingKeyException();
        }

        this->values[k] = std::make_shared<JsonValue>(v);
    }

    void removeValue(KeyType k) {
        this->values.erase(k);
    }

    void updateValue(KeyType k, ValuePointer v) {
        if (this->values.find(k) == std::end(this->values)) {
            throw InvalidKeyException();
        }

        this->values[k] = v;
    }

    template<typename ValueType>
    void updateValue(KeyType k, ValueType v) {
        if (this->values.find(k) == std::end(this->values)) {
            throw InvalidKeyException();
        }

        this->values[k] = std::make_shared<JsonValue>(v);
    }

    std::string getValue() const override { return this->serialise(); }

    std::string serialise() const override {
        std::stringstream ss;
        ss << "{";
        auto first = std::begin(this->values);
        auto last = std::end(this->values);
        do {
            ss << '\"' << first->first << '\"'
               << ":" << first->second->serialise();
        } while (++first != last && ss << ",");
        ss << "}";

        return ss.str();
    }

    virtual void deserialise(const std::string str, size_t& pos) override {
        pos++; // skip {
        while (str[pos] != '}') {
            std::string k = this->readString(str, pos);
            pos++; // skip :
            if (str[pos] == '{') {
                ValuePointer v = std::make_shared<JsonObject>();
                v->deserialise(str, pos);
                this->addValue(k, v);
            } else {
                ValuePointer v = std::make_shared<JsonValue>();
                v->deserialise(str, pos);
                this->addValue(k, v);
            }
            if (str[pos] == ',') pos++;
        }
        pos++;
    }

private:
    std::unordered_map<KeyType, ValuePointer> values;
};

} // namespace JsonLib

#endif