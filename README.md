# ProtoCross Examples

Runnable examples for [ProtoCross](https://github.com/IsaacSherman/ProtoCross).

## ValueWithUncertainty

`UncertaintyDemo` builds symmetric and asymmetric uncertainty messages from the same ProtoCross factories in C# and C++. Run the commands below from the `UncertaintyDemo` directory. The generators write to `generated/csharp` and `generated/cpp`.

### C#

Install the .NET 10 SDK, [ProtoCross](https://github.com/IsaacSherman/ProtoCross#install), and [protoc](https://protobuf.dev/installation/). Make sure `protocross` and `protoc` are on your PATH.

```sh
protocross build valueWithUncertainty.pcross --target csharp --out generated
protoc --proto_path=. --csharp_out=generated/csharp valueWithUncertainty.proto
dotnet run --project CSharp/UncertaintyDemo.csproj
```

### C++

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
