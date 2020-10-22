{
    "variables": {
        "libs": "<@(module_root_dir)/libs"
    },
    "targets": [
        {
            "target_name": "glinfo",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": [
                "./src/glinfo.cpp",
                "./src/main.cpp"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "<@(module_root_dir)/include/"
            ],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "msvs_settings": {
                "VCLinkerTool": {
                    "IgnoreDefaultLibraryNames": ["libcmtd.ib", "libcmt.lib"]
                }
            },
            "conditions": [
                [
                    "OS=='linux'",
                    {
                        "libraries": [
                            "-Wl,-rpath=\'$${ORIGIN}/../../../libs/linux'",
                            "<(libs)/linux/libglfw.so.3"
                        ]
                    }
                ],
                [
                    "OS=='win' and target_arch=='x32'",
                    {
                        "libraries": [
                            "<(libs)/win32/glfw3dll.lib",
                            "opengl32.lib"
                        ]
                    }
                ],
                [
                    "OS=='win' and target_arch=='x64'",
                    {
                        "libraries": [
                            "<(libs)/win64/glfw3.lib",
                            "opengl32.lib"
                        ]
                    }
                ],
                [
                    "OS=='mac'",
                    {
                        "xcode_settings": {
                            "OTHER_LDFLAGS": [
                                "<(libs)/darwin/libglfw.3.dylib",
                                "-Wl,-rpath -Wl,@loader_path/../../../libs/darwin"
                            ]
                        }
                    }
                ]
            ]
        }
    ]
}