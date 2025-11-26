{
  description = "C++ LeetCode solutions with Bazel";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            # Bazel build system (bazelisk downloads pre-built binaries)
            bazelisk

            # C++ toolchain (LLVM/Clang)
            llvmPackages_18.clang
            llvmPackages_18.llvm
            llvmPackages_18.libcxx

            # Build essentials
            gcc
            gnumake
            cmake
            pkg-config

            # Python (for some scripts in BUILD.bazel)
            python3

            # Development tools
            git

            # Create a bazel wrapper script
            (pkgs.writeShellScriptBin "bazel" ''
              exec ${pkgs.bazelisk}/bin/bazelisk "$@"
            '')
          ];

          shellHook = ''
            # Set up Clang as the default compiler
            export CC="${pkgs.llvmPackages_18.clang}/bin/clang"
            export CXX="${pkgs.llvmPackages_18.clang}/bin/clang++"

            # Bazel needs to know where to find tools
            export BAZEL_USE_CPP_ONLY_TOOLCHAIN=1

            echo "🚀 Bazel C++ development environment loaded"
            echo "   Bazel version: $(bazel --version 2>/dev/null || echo 'not found')"
            echo "   Clang version: $(clang --version | head -n1)"
            echo ""
            echo "You can now run: bazel build //..."
          '';
        };
      }
    );
}
