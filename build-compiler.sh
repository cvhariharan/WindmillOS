export TARGET="i386-elf"
export PREFIX="$PWD/cross-compiler/cross"
export PATH="$PREFIX/bin:$PATH"

mkdir -p cross-compiler
cd cross-compiler
wget https://ftp.gnu.org/gnu/binutils/binutils-2.37.tar.gz
tar xf binutils-2.37.tar.gz

mkdir -p build-binutils
cd build-binutils
../binutils-2.37/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make -j4
make install


cd ..
mkdir -p build-gcc
wget https://ftp.gnu.org/gnu/gcc/gcc-11.1.0/gcc-11.1.0.tar.gz
tar xf gcc-11.1.0.tar.gz
cd gcc-11.1.0
./contrib/download_prerequisites

cd ../build-gcc
../gcc-11.1.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc -j4
make all-target-libgcc -j4
make install-gcc
make install-target-libgcc
