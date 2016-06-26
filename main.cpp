#include "TrainLeg.h"
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int find_train_minprice(vector<TrainLeg> V, int ArrivalStationId, int DepartureStationId);
float const MAX = 100000;
  
int f = 1, s = 4;        // конечная и стартовая вершины например
vector<int> way;
vector<TrainLeg> read()
{
	TrainLeg Obj;
	vector<TrainLeg> myTrainLeg;
	ifstream file;
	file.open("1.xml");
	if (file.is_open())
		cout << "file is open! Wait for work"<<endl;
	else
	{
		cout << "file not open!";
		exit(1);
	}
	string buf;

	getline(file, buf);//xml версия не нужна
	getline(file, buf);//имя класса нам не нужно

	while (getline(file, buf))
	{
		if (buf == "</TrainLegs>")
		{
			break;
		}
		//cout << buf<<"size=="<<buf.size()<<endl;
		for (auto i = 0; i < buf.size(); ++i)
		{
			string temp_for_class;
			int index_line_class = 0;
			int index = buf.find(NAMECLASSLINE[index_line_class]);
			//1 TrainId
			if (index)
			{
				while (true)
				{
					if (buf[index] == '\"')
					{
						index++; break;
					}
					index++;
				}
				while (true)
				{
					if (buf[index] == '\"')
						break;
					temp_for_class += buf[index];
					index++;
				}
				Obj.setTrainId(temp_for_class);
			//	cout<<temp_for_class<< endl;
			}
			index_line_class++;
			temp_for_class.clear();
			//2 DepartureStationId
			index = buf.find(NAMECLASSLINE[index_line_class]);
			if (index)
			{
				while (true)
				{
					if (buf[index] == '\"')
					{
						index++; break;
					}
					index++;
				}
				while (true)
				{
					if (buf[index] == '\"')
						break;
					temp_for_class += buf[index];
					index++;
				}
				Obj.setDepartureStationId(temp_for_class);
				//cout << temp_for_class << endl;
			}
			temp_for_class.clear();
			index_line_class++;
			//3 ArrivalStationId
			index = buf.find(NAMECLASSLINE[index_line_class]);
			if (index)
			{
				while (true)
				{
					if (buf[index] == '\"')
					{
						index++; break;
					}
					index++;
				}
				while (true)
				{
					if (buf[index] == '\"')
						break;
					temp_for_class += buf[index];
					index++;
				}
				Obj.setArrivalStationId(temp_for_class);
			//	cout << temp_for_class << endl;
			}
			temp_for_class.clear();
			index_line_class++;
			//4 Price
			index = buf.find(NAMECLASSLINE[index_line_class]);
			if (index)
			{
				while (true)
				{
					if (buf[index] == '\"')
					{
						index++; break;
					}
					index++;
				}
				while (true)
				{
					if (buf[index] == '\"')
						break;
					temp_for_class += buf[index];
					index++;
				}
				Obj.setPrice(temp_for_class);
			//	cout << temp_for_class << endl;
			}
			temp_for_class.clear();
			index_line_class++;
			//5 ArrivalTimeString
			index = buf.find(NAMECLASSLINE[index_line_class]);
			if (index)
			{
				while (true)
				{
					if (buf[index] == '\"')
					{
						index++; break;
					}
					index++;
				}
				while (true)
				{
					if (buf[index] == '\"')
						break;
					temp_for_class += buf[index];
					index++;
				}
				Obj.setArrivalTimeString(temp_for_class);
			//	cout << temp_for_class << endl;
			}
			temp_for_class.clear();
			index_line_class++;
			//5 ArrivalTimeString
			index = buf.find(NAMECLASSLINE[index_line_class]);
			if (index)
			{
				while (true)
				{
					if (buf[index] == '\"')
					{
						index++; break;
					}
					index++;
				}
				while (true)
				{
					if (buf[index] == '\"')
						break;
					temp_for_class += buf[index];
					index++;
				}
				Obj.setDepartureTimeString(temp_for_class);
			//	cout << temp_for_class << endl;
			}
			temp_for_class.clear();
			index_line_class++;


		}
		myTrainLeg.push_back(Obj);
	}
	return myTrainLeg; 
}
vector<int> CountStantion(vector<TrainLeg> &AllTrain)
{
	vector<int> AllStantion;
	for (auto i = 0; i < AllTrain.size(); i++)
	{
		//1
		vector<int>::iterator it;
		it = find(AllStantion.begin(), AllStantion.end(), AllTrain[i].getArrivalStationId());
		if (it == AllStantion.end())
			AllStantion.push_back(AllTrain[i].getArrivalStationId());
		//2
		it = find(AllStantion.begin(), AllStantion.end(), AllTrain[i].getDepartureStationId());
		if (it == AllStantion.end())
			AllStantion.push_back(AllTrain[i].getDepartureStationId());
	}
	return AllStantion;
}
void Travel(int v,int s,int** par)
{
	way.push_back((v));
	if (v == s)
	{
		
		//cout << v + 1 << " ";
	}
	else
	{
		Travel(par[s][v],s,par);
		//cout << v +1 << " ";
	}
}


void Floyd(float **D,int**par,int n)
{
	bool fl = true;
	while (fl) {
		fl = false;
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					if (D[i][j] > D[i][k] + D[k][j])
					{
						D[i][j] = D[i][k] + D[k][j];
						par[i][j] = par[k][j];
						fl = true;
					}
	}
}

int main()
{
	s--; f--;
	vector<TrainLeg> AllTrain(read());//считывание xml файла
	//AllTrain[0].ShowAll();
	vector<int> arrayNumStantion(CountStantion(AllTrain));//массив всех доступных станций
	cout << "Stantion:";
	for (int i = 0; i < arrayNumStantion.size();++i)
	{
		cout<<arrayNumStantion[i]<<" ";
	}
	//
	float **graphCost = new float*[arrayNumStantion.size()];//матрица стоимости
	for (int count = 0; count < arrayNumStantion.size(); count++)
		graphCost[count] = new float[arrayNumStantion.size()]; 
	int **next = new int*[arrayNumStantion.size()];//массив предков для восстановления пути
	for (int count = 0; count < arrayNumStantion.size(); count++)
		next[count] = new int[arrayNumStantion.size()];

	//
	//инициализация максимумами
	for (int i = 0; i < arrayNumStantion.size(); ++i)
		for (int j = 0; j < arrayNumStantion.size(); ++j)
			graphCost[i][j] = MAX;

	//
	for (int i = 0; i < arrayNumStantion.size(); ++i)
		for (int j = 0; j < arrayNumStantion.size(); ++j)
		{
			next[i][j] = i;
			if (i == j)
			{
				graphCost[i][j] = 0;
				continue;
			}
			int ind = find_train_minprice(AllTrain, arrayNumStantion[i], arrayNumStantion[j]);
			if (ind != -1)
			{
				graphCost[i][j] = AllTrain[ind].getPrice();
				continue;
			}
		}
	//
	cout << endl<<endl<<endl;
	cout << "Initial Matrix: "<<endl;
	for (int i = 0; i < arrayNumStantion.size(); ++i,cout<<endl)
		for (int j = 0; j < arrayNumStantion.size(); ++j)
			cout << graphCost[i][j] << "\t";

	int n = arrayNumStantion.size();
	Floyd(graphCost, next, n);
	//
	cout << endl << endl << endl;
	if (graphCost[s][f] < MAX)
	{
		cout << "Way " << arrayNumStantion[f] << " -> " << arrayNumStantion[s]<<endl;
		cout<<"MIN Price = ";
		cout << graphCost[s][f] << endl;
		Travel(s, f, next);
		cout << "All way: ";
		for (int i = way.size()-1; i >=0 ; --i)
			cout <<arrayNumStantion[way[i]]<<" ";
	}
	else
	{
		cout << "Way " << arrayNumStantion[f] << " -> " << arrayNumStantion[s]<< "not found"<<endl;
	}
	//
	cout << endl << endl << endl;
	cout << "Matrix min price:" << endl;
	for (int i = 0; i < arrayNumStantion.size(); ++i, cout << endl)
		for (int j = 0; j < arrayNumStantion.size(); ++j)
			cout << graphCost[i][j] << "\t";
	system("pause");
	return 0;
}
int find_train_minprice(vector<TrainLeg> V, int ArrivalStationId, int DepartureStationId)
{
	int ind = -1;
	double price = MAX;
	for (int i = 0; i < V.size(); i++)
	{
		if (V[i].getArrivalStationId() == ArrivalStationId && V[i].getDepartureStationId() == DepartureStationId)
		{
			if (price > V[i].getPrice())
			{
				price = V[i].getPrice();
				ind = i;
			}
		}
	}
	return ind;//индекс в массиве поездов, у которого минимальная стоимость(их несколько может быть), по надобности легко можно восстановить все поезда которые идут с минимальной стоимостью
}