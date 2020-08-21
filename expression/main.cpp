#include "Common.h"
#include "test_runner.h"

#include <sstream>

using namespace std;

class ValueExp : public Expression {
public:
    ValueExp(int value) : value_(value) {}

    int Evaluate() const override {
        return value_;
    }

    std::string ToString() const override {
        return std::to_string(value_);
    }

private:
    int value_;
};

class SumExp : public Expression {
public:
    SumExp(ExpressionPtr val1, ExpressionPtr val2)
            : val_1(std::move(val1)), val_2(std::move(val2)) {}

    int Evaluate() const override {
        return val_1->Evaluate() + val_2->Evaluate();
    }

    std::string ToString() const override {
        return "(" + val_1->ToString() + ")+(" + val_2->ToString() + ")";
    }

private:
    ExpressionPtr val_1;
    ExpressionPtr val_2;
};

class ProductExp : public Expression {
public:
    ProductExp(ExpressionPtr val1, ExpressionPtr val2)
            : val_1(std::move(val1)), val_2(std::move(val2)) {}

    int Evaluate() const override {
        return val_1->Evaluate() * val_2->Evaluate();
    }

    std::string ToString() const override {
        return "(" + val_1->ToString() + ")*(" + val_2->ToString() + ")";
    }

private:
    ExpressionPtr val_1;
    ExpressionPtr val_2;
};


ExpressionPtr Value(int value) {
    return make_unique<ValueExp>(value);
}

ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
    return make_unique<SumExp>(move(left), move(right));
}

ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
    return make_unique<ProductExp>(move(left), move(right));
}

string Print(const Expression *e) {
    if (!e) {
        return "Null expression provided";
    }
    stringstream output;
    output << e->ToString() << " = " << e->Evaluate();
    return output.str();
}

void Test() {
    ExpressionPtr e1 = Product(Value(2), Sum(Value(3), Value(4)));
    ASSERT_EQUAL(Print(e1.get()), "(2)*((3)+(4)) = 14");

    ExpressionPtr e2 = Sum(move(e1), Value(5));
    ASSERT_EQUAL(Print(e2.get()), "((2)*((3)+(4)))+(5) = 19");

    ASSERT_EQUAL(Print(e1.get()), "Null expression provided");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, Test);
    return 0;
}