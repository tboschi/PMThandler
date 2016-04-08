OUT = TExtracter
IN = TreeExtracter

ROOT = -pthread -m64 -I/usr/include/root -L/usr/lib64/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lMathCore -lThread -pthread -lm -ldl -rdynamic	

all:	clean libPMTH
	g++ $(IN).cpp $(ROOT) -I../inc/ -L./ -lPMTH -fPIC -o $(OUT)


clean:
	rm -f $(OUT)
	rm -f libPMTH*

libPMTH:
	g++ -shared -fPIC -I../inc/ ../inc/PMTH.C -o libPMTH.so $(ROOT)
