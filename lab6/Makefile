compile:
	mkdir -p build

nextFloorSingleStop: 
	mkdir -p buildDir
	#cp *.bo buildDir/
	bsc -u -sim -bdir buildDir -info-dir buildDir -simdir buildDir -vdir buildDir -aggressive-conditions -show-range-conflict Tb.bsv
	bsc -sim -e mkNextFloorUpStop -bdir buildDir -info-dir buildDir -simdir buildDir -o simNextFloorUpStop buildDir/*.ba
	bsc -u -sim -bdir buildDir -info-dir buildDir -simdir buildDir -vdir buildDir -aggressive-conditions -show-range-conflict Tb.bsv
	bsc -sim -e mkNextFloorDownStop -bdir buildDir -info-dir buildDir -simdir buildDir -o simNextFloorDownStop buildDir/*.ba

nextFloorStop: 
	mkdir -p buildDir
	cp *.bo *.ba buildDir/
	bsc -u -sim -bdir buildDir -info-dir buildDir -simdir buildDir -vdir buildDir -aggressive-conditions -show-range-conflict Tb.bsv
	bsc -sim -e mkNextFloorStop -bdir buildDir -info-dir buildDir -simdir buildDir -o simNextFloorStop buildDir/*.ba
	


rules: compile
	bsc -u -sim -simdir +RTS -K140M -RTS build -bdir build -info-dir build -show-range-conflict -no-warn-action-shadowing -keep-fires -p .:%/Prelude:%/Libraries:%/Libraries/BlueNoC -g mkRules Tb.bsv
	bsc -e mkRules -sim -o ./simRules -simdir build -no-warn-action-shadowing -p %/Prelude:%/Libraries:%/Libraries/BlueNoC -bdir build -keep-fires

10floor: compile
	bsc -u -sim -simdir +RTS -K140M -RTS build -bdir build -info-dir build -show-range-conflict -no-warn-action-shadowing -keep-fires -p .:%/Prelude:%/Libraries:%/Libraries/BlueNoC -g mk10Floors Tb10f.bsv
	bsc -e mk10Floors -sim -o ./sim10Floors -simdir build -no-warn-action-shadowing -p %/Prelude:%/Libraries:%/Libraries/BlueNoC -bdir build -keep-fires

staff: 
	mkdir -p buildDir
	bsc -u -sim -bdir buildDir -info-dir buildDir -simdir buildDir -vdir buildDir -aggressive-conditions -show-range-conflict staffElevator.bsv


tbnextstop: 
	mkdir -p buildDir
	bsc -u -sim -bdir buildDir -info-dir buildDir -simdir buildDir -vdir buildDir -aggressive-conditions -show-range-conflict TbNextFloor.bsv
	bsc -sim -e mkTbNextFloor -bdir buildDir -info-dir buildDir -simdir buildDir -o simSimTbNextFloor buildDir/*.ba


clean:
	rm -rf buildDir sim* out verilog dump.vcd build




.PHONY: compile nextFloorSingleStop nextFloorStop rules 10floor clean
.DEFAULT_GOAL: nextFloorSingleStop
