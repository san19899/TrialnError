//#ifndef CSV_H
//#define CSV_H
//
//#include <iomanip>
//using std::endl;
//
//#include <fstream>
//using std::ifstream;
//using std::ofstream;
//
//#include <string>
//using std::string;
//
//#include <vector>
//using std::vector;
//
//class csv
//{
//	friend bool operator==(const csv &, const csv &);
//	friend bool operator!=(const csv &, const csv &);
//
//public:
//	csv();
//	csv(char*);
//	void read(char*);
//	void write(char*);
//	string getfield(int, int);
//	void setfield(int, int, string);
//	const csv &operator=(const csv &);
//	int rows, cols;
//
//private:
//	vector < vector <string> > data;
//};
//
//csv::csv()
//{
//	rows = cols = 0;
//	data.push_back(vector <string>());
//}
//
//csv::csv(char* fname)
//{
//	read(fname);
//}
//
//const csv &csv::operator=(const csv &n)
//{
//	rows = n.rows;
//	cols = n.cols;
//	data = n.data;
//
//	return *this;
//}
//
//void csv::read(char* fname)
//{
//	ifstream in(fname);
//	string element, delimiters = ",\n\r";
//	char ch;
//
//	rows = cols = 0;
//	data.clear();
//
//	data.push_back(vector <string>());
//
//	while (in.read((char*)&ch, 1))
//	{
//		if (delimiters.find_first_of(ch) == delimiters.npos)
//			element += ch;
//
//		else
//		{
//			if (ch != '\r')
//			{
//				data[rows].push_back(element);
//				element = "";
//				if (ch == '\n')
//				{
//					data.push_back(vector <string>());
//					rows++;
//				}
//			}
//		}
//	}
//
//	in.close();
//	data[rows].push_back(element);
//	cols = data[0].size();
//	rows = data.size();
//}
//
//void csv::write(char* fname)
//{
//	ofstream out(fname);
//
//	for (int x = 0; x < rows; x++)
//	{
//		for (int y = 0; y < cols; y++)
//		{
//			out << data[x][y];
//			if (y != cols - 1)
//				out << ",";
//		}
//		out << endl;
//	}
//
//	out.close();
//}
//
//string csv::getfield(int x, int y)
//{
//	return data[x][y];
//}
//
//void csv::setfield(int x, int y, string val)
//{
//	data[x][y] = val;
//}
//
//bool operator==(const csv &d1, const csv &d2)
//{
//	return d1 == d2;
//}
//
//bool operator!=(const csv &d1, const csv &d2)
//{
//	return d1 != d2;
//}
//
//#endif