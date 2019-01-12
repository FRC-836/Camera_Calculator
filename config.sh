mkdir build

pushd build
mkdir Debug
mkdir Release

pushd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
popd

pushd Release
cmake -DCMAKE_BUILD_TYPE=Release ../..
popd
