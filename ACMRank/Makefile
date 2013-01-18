CXX = g++
CXXFLAGS = -g -Wall

a.out: RankList.o Team.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp RankList.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

RankList.o: RankList.cpp RankList.h Team.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Team.o: Team.cpp Team.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o a.out

