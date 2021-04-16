from conans import ConanFile, CMake, tools

class ClientAppConan(ConanFile):
    name = "clientapp"
    version = "0.1.0"
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "This recipe file is used to build an executable of device app"
    topics = ("<Put some tag here>", "<here>", "<and here>")
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [ True, False ]
    }
    default_options = {
        "shared": False
    }
    generators = "cmake"
    default_user = "jenkins"
    default_channel = "master"

    def configure(self):
        try:
            self.options["cococlientsdk"].environment
        except:
            self.output.info("cococlientsdk:environment: UNSET")
            switcher = {
                "develop": "DEV",
                "release": "QA",
                "hotfix": "QA",
                "master": "PROD"
            }
            self.options["cococlientsdk"].environment = switcher.get(self.channel)
            self.output.info("cococlientsdk:environment: " + switcher.get(self.channel))
        try:
            self.options["cococlientsdk"].cmake_build_type
        except:
            self.output.info("cococlientsdk:cmake_build_type: UNSET")
            switcher = {
                "develop": "Debug",
                "release": "Debug",
                "hotfix": "Release",
                "master": "Release"
            }
            self.options["cococlientsdk"].cmake_build_type = switcher.get(self.channel)
            self.output.info("cococlientsdk:cmake_build_type: " + switcher.get(self.channel))

    def requirements(self):
        if self.user and self.channel:
            default_user = self.user
            default_channel = self.channel
        self.requires("cococlientsdk/[~0.61.0]@%s/%s" % (default_user, default_channel))
    
    def imports(self):
        if not tools.is_apple_os(self.settings.os):
            self.copy("libcococlientsdk.so", dst="lib", src="lib")
        self.copy("*", dst="include/cococlientsdk", src="include/cococlientsdk")

    def build(self):
        cmake = CMake(self)
        cmake.definitions["Platform"] = self.settings.os
        cmake.configure(source_folder=".")
        cmake.build()

    def package(self):
        self.copy("*", dst="bin", src="bin", keep_path=False)
        self.copy("*", dst="include", src="include")
        if not tools.is_apple_os(self.settings.os):
            self.copy("*", dst="lib", src="lib")
