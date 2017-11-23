#!/usr/bin/env python

import os

BUILD_DIR = "./lib/android"

ANDROID_ROOT_NDK = os.environ['ANDROID_HOME'] + '/ndk-bundle'
TOOLCHAIN = ANDROID_ROOT_NDK + '/build/cmake/android.toolchain.cmake'

ARCHS_PROFILE_ALL = [
   ["armeabi-v7a", "android-19", ANDROID_ROOT_NDK + "/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/arm-linux-androideabi/bin/strip"],
   ["arm64-v8a", "android-21", ANDROID_ROOT_NDK + "/toolchains/aarch64-linux-android-4.9/prebuilt/darwin-x86_64/aarch64-linux-android/bin/strip"],
   ["x86", "android-21", ANDROID_ROOT_NDK + "/toolchains/x86-4.9/prebuilt/darwin-x86_64/i686-linux-android/bin/strip"], 
   ["x86_64", "android-19", ANDROID_ROOT_NDK + "/toolchains/x86_64-4.9/prebuilt/darwin-x86_64/x86_64-linux-android/bin/strip"]
]

def build_arch(archs_profile):
    
    ARCH_NAME = archs_profile[0]
    ANDROID_NATIVE_API_LEVEL = archs_profile[1]
    STRIPPER = archs_profile[2]
    
    print("[!] Target SDK set to {} .".format(ANDROID_NATIVE_API_LEVEL))

    os.system('rm CMakeCache.txt')
    os.system('rm -r CMakeFiles')
    os.system('echo pwd')
    os.system(
        'unset CFLAGS LDFLAGS CPPFLAGS CXXFLAGS LDLIBS;'
        'export CFLAGS="-O3";'
        'export LDFLAGS="-w -s";'
        'export CPPFLAGS=$CFLAGS;'
        'export CXXFLAGS="$CFLAGS -std=c++11";'
        'export LDLIBS="z";'
        'cmake -DCMAKE_TOOLCHAIN_FILE={} '
            '-DANDROID_NDK="{}" '
            '-DANDROID_STL="gnustl_static" '
            '-DANDROID_NATIVE_API_LEVEL="{}" '
            '-DANDROID_ABI="{}" '
            '-DANDROID_TOOLCHAIN=clang '
            '-DCMAKE_BUILD_TYPE=Release ' 
            '-DASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT=FALSE '
            '-DASSIMP_BUILD_FBX_IMPORTER=TRUE '
            '-DENABLE_BOOST_WORKAROUND=OFF '
            '-DBUILD_SHARED_LIBS=ON '
            '-DASSIMP_BUILD_TESTS=OFF '
            '-DASSIMP_BUILD_ASSIMP_TOOLS=OFF '
            '-DASSIMP_NO_EXPORT=ON '
        .format(TOOLCHAIN, ANDROID_ROOT_NDK, ANDROID_NATIVE_API_LEVEL, ARCH_NAME)
    )

    print("[!] Building {} library".format(ARCH_NAME))

    os.system('make clean')
    os.system('make assimp -j 8')
    print("[!] Moving built library into: {}/{}/".format(BUILD_DIR, ARCH_NAME))

    os.system('{} ./lib/libassimp.so'.format(STRIPPER))
    os.system('mv ./lib/libassimp.so {}/{}/'.format(BUILD_DIR, ARCH_NAME))
    

print("[!] Assimp Android build script")

os.chdir('../../')
os.system('rm -rf {}'.format(BUILD_DIR))

for profile in ARCHS_PROFILE_ALL:
    os.system('mkdir -p {}/{}'.format(BUILD_DIR, profile[0]))
    build_arch(profile)


