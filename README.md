# Classification
RTTI & Creating by class name 

## Configure
```bash
mkdir build; cd build
cmake -G "<generator>" ..
```

## Build
```bash
cmake --build .
```

## Test
### Unix Makefiles
```bash
cmake --build . --target test
```
### Visual Studio Solution files
```bash
cmake --build . --target RUN_TESTS
```