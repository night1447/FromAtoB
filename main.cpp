#include "function.h"
using namespace std;
int main() {
    try {
        string path = "input.txt";
        //Initialization user Reader
        UserReader userReader;
        //Initialization from file transports
        Transports transports = initTransportsFromFile(path);
        //Initialization user
        string begin = userReader.readStation(true, transports.getMap()),
                end = userReader.readStation(false, transports.getMap());
        bool choose = userReader.readUserChooseRoute();
        User user(begin, end, choose);
        //Initialization algorithm Dijkstra
        AlgorithmDijkstra algorithmDijkstra(user.getChoose(), transports, user.getUserStation(), user.getEndStation());
        MainClass main(algorithmDijkstra, transports);
        //Initialization writer
        Writer writer;
        writer.outputMain(main);
        cout << "Программа закончила работу."<<endl;
    }
    catch (Exception& exception){
        cout << exception.GetException() <<endl;
    }
}
