// ----------------------------------------------------------------------------------------------------

function assert(expression, message) {
    if (!expression) {
        throw new Error(message || "Assertion failed");
    }
}

// ----------------------------------------------------------------------------------------------------

suite("add", function() {

    test("add(1, 2)", function() {
        const result = calculatorModule.add(1, 2);
        assert(result === 3);
    });

});

// ----------------------------------------------------------------------------------------------------

suite("subtract", function() {

    test("subtract(1, 2)", function() {
        const result = calculatorModule.subtract(1, 2);
        assert(result === -1);
    });

});

// ----------------------------------------------------------------------------------------------------

suite("multiply", function() {

    test("multiply(1, 2)", function() {
        const result = calculatorModule.multiply(1, 2);
        assert(result === 2);
    });

});

// ----------------------------------------------------------------------------------------------------

suite("divide", function() {

    test("divide(1, 2)", function() {
        const result = calculatorModule.divide(1, 2);
        assert(result === 0.5);
    });

});

// ----------------------------------------------------------------------------------------------------
