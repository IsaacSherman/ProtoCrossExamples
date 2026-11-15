# ProtoCross Examples

Runnable examples for [ProtoCross](https://github.com/IsaacSherman/ProtoCross).

## ValueWithUncertainty

`UncertaintyDemo` holds the code for the ValueWithUncertainty series on [ProtoCross.dev](https://protocross.dev/). Each post has a tag with the code as that post leaves it:

| Post | Tag |
| --- | --- |
| [Part 1: Factories](https://protocross.dev/blog/valuewithuncertaintydemo1/) | `UncertaintyDemoPart1` |
| [Part 2: Functions and Unit Tests](https://protocross.dev/blog/valuewithuncertaintydemo2/) | `UncertaintyDemoPart2A`, then `UncertaintyDemoPart2B` |

Run the commands below from the `UncertaintyDemo` directory.

### Part 1: Factories

Part 1 builds symmetric and asymmetric uncertainty messages from the same ProtoCross factories in C# and C++. The generators write to `generated/csharp` and `generated/cpp`.

#### C#

Install the .NET 10 SDK, [ProtoCross](https://github.com/IsaacSherman/ProtoCross#install), and [protoc](https://protobuf.dev/installation/). Make sure `protocross` and `protoc` are on your PATH.

```sh
protocross build valueWithUncertainty.pcross --target csharp --out generated
protoc --proto_path=. --csharp_out=generated/csharp valueWithUncertainty.proto
dotnet run --project CSharp/UncertaintyDemo.csproj
```

#### C++

The Windows commands below use PowerShell, CMake, Visual Studio with C++20 support, and an x64 protobuf installation. Use the compiler and C++ runtime from the same protobuf release. Set `$protobuf` to your installation directory. The example shows the path for vcpkg in classic mode.

```powershell
$protobuf = 'C:\vcpkg\installed\x64-windows'
$env:Path = "$protobuf\tools\protobuf;$protobuf\bin;$env:Path"

protocross build valueWithUncertainty.pcross --target cpp --out generated
protoc --proto_path=. --cpp_out=generated/cpp valueWithUncertainty.proto
cmake -S CPP -B CPP/build -A x64 "-DCMAKE_PREFIX_PATH=$protobuf"
cmake --build CPP/build --config Release
.\CPP\build\Release\uncertainty_demo.exe
```

Both programs print a measurement of 10 with symmetric uncertainty 0.5, then a measurement of 10 with asymmetric uncertainty +0.75 and −0.25.

### Part 2: Functions and unit tests

Part 2 adds addition and subtraction to the message in `valueWithUncertainty.pcross`, and tests them in `valueWithUncertainty_tests.pcross`. `protocross test` generates the tests in C# and C++, then builds and runs them with `dotnet test` and with CMake and CTest. It needs the tools from both Part 1 walkthroughs, with `CMAKE_PREFIX_PATH` set to your protobuf installation:

```powershell
$protobuf = 'C:\vcpkg\installed\x64-windows'
$env:Path = "$protobuf\tools\protobuf;$protobuf\bin;$env:Path"
$env:CMAKE_PREFIX_PATH = $protobuf

protocross test UncertaintyDemo.pcproj
```

`UncertaintyDemo.pcproj` lists both source files. It also stops VS Code from flagging the tests file. Without it, name the files instead: `protocross test valueWithUncertainty.pcross valueWithUncertainty_tests.pcross`. To test one language, add `-t csharp` or `-t cpp`.

At `UncertaintyDemoPart2A`, one of the two tests fails in both languages: `Subtract` adds the values where it should subtract them. `UncertaintyDemoPart2B` fixes `Subtract` and adds 14 more tests, and all 16 pass.
