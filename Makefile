all: prepare compile

prepare:
	cmake -H. -B_builds

compile:
	cmake --build _builds

install:
	cmake --build _builds --target install

uninstall:
	cmake --build _builds --target uninstall

clean:
	rm -r _builds

