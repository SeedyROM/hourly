develop:
	cmake --build ./cmake-build-debug --target space_invaders -- -j 4

run:
	cd ./cmake-build-debug/; ./space_invaders