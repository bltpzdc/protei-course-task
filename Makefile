clean:
	rm -rf build/ \
	rm CMakeUserPresets.json

build:
	conan install . --output-folder=build --build=missing &&\
 	cd build/ &&\
 	cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release &&\
	cmake --build . &&\
	cd ..

run:
	./build/CallCenter





