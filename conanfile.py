from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, cmake_layout


class ProtoConan(ConanFile):
    name = "proto-example"
    homepage = "https://github.com/PhilipMourdjis/conan-2-protobuf"
    url = "https://github.com/PhilipMourdjis/conan-2-protobuf"
    license = "MIT"
    description = "Example protobuf / conan 2.0 project"
    settings = "os", "arch", "compiler", "build_type"
    no_copy_source = True
    version = "1.0"

    def configure(self):
        self.options["protobuf/*"].shared = True
        self.options["protobuf/*"].debug_suffix = False
        self.options["protobuf/*"].with_zlib = False
        self.options["protobuf/*"].with_rtti = False
        self.options["protobuf/*"].lite = False

    def generate(self):
        tc = CMakeToolchain(self)
        tc.user_presets_path = False
        tc.cache_variables["CMAKE_POSITION_INDEPENDENT_CODE"] = True
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("protobuf/3.21.12")

    def build(self):
        pass

    def package(self):
        pass
