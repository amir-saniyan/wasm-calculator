# Wasm Calculator

In the name of God

This project can be used as a template to build `WebAssembly` (`Wasm`) modules.

This project successfully built on `Ubuntu 20.04`.

## Prerequisites

**Install Build Tools**:

```shell
$ sudo apt install build-essential cmake git
```

**Install Emscripten SDK**:

```shell
$ cd ~
$ git clone https://github.com/emscripten-core/emsdk.git

$ cd emsdk
$ ./emsdk install latest
$ ./emsdk activate latest
```

## Build

To build this project, run the following commands in the terminal:

```shell
$ source ~/emsdk/emsdk_env.sh

$ mkdir build

$ cd build

$ emcmake cmake \
    -D CMAKE_BUILD_TYPE=Release \
    ..

$ cmake \
    --build .
    
$ emrun \
    --serve_root . \
    "test/test.htm"
```

Alternatively, you can run the `build.sh` script:

```shell
$ ./build.sh

# --- or ---

$ ./build.sh --no_browser
```

## Deployment

To deploy `Wasm Calculator` on a website, you should upload `calculator.js` and `calculator.wasm` files.

The following HTML code shows how to use these files:

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">

        <title>Wasm Calculator</title>

        <script src="./calculator.js"></script>

        <script>
            let calculatorModule;

            createCalculator()
            .then(module => {
                calculatorModule = module;

                console.log("calculatorModule:", calculatorModule);

                console.log("getMajorVersion():", calculatorModule.getMajorVersion());

                console.log("getMinorVersion():", calculatorModule.getMinorVersion());

                console.log("getPatchVersion():", calculatorModule.getPatchVersion());

                console.log("getVersionString():", calculatorModule.getVersionString());

                console.log("add(1, 2):", calculatorModule.add(1, 2));

                console.log("subtract(1, 2):", calculatorModule.subtract(1, 2));

                console.log("multiply(1, 2):", calculatorModule.multiply(1, 2));

                console.log("divide(1, 2):", calculatorModule.divide(1, 2));
            })
            .catch(function(error) {
                console.error("createCalculator failed:", error);
            });
        </script>
    </head>
    <body>
        <h1 style="text-align: center;">Wasm Calculator</h1>
    </body>
</html>
```

**Note**:

If you try to open HTML file directly from your local hard drive (e.g. `file://your_path/wasm_calculator.html`), you will end up with an error message along the lines of `both async and sync fetching of the wasm failed`.
You need to run your HTML file through an HTTP server (`http://`).

## Resources

* https://webassembly.org
* https://emscripten.org
* https://mochajs.org
