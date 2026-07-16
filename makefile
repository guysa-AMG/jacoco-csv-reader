version := "1.0.1"
name := "jcov"

all: build
	echo "built Complete"

build:
	mkdir -p build/${version}
	g++ src/main.cxx -o  build/${version}/${name}

clean:
	rm -rf build

install:
	sudo cp build/${version}/${name} /usr/bin