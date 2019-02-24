#if 0

#include<iostream>

using namespace std;

template<class T>
class Solution{
public:
	T Add(const T& a, const T& b){
		return a + b;
	}
};

template<class T,class W>
class Test{
public:
	W Add(const T& a, const W& b){
		return (a + b);
	}
};

template<class T,class W>
T Add(const T& a, const W& b){
	return a + b;
}


int main(){
	/*Solution<int> s;
	Test<int, double> t;
	cout << s.Add(1, 2) << endl;
	cout << t.Add(1,3) << endl;*/
	cout << Add<double>(1, 2.2) << endl;
	system("pause");
	return 0;
}

#endif

//#include<iostream>
//using namespace std;
//
//
//template<bool T, class T1, class T2>
//class IfThenElse;
//
//template<class T1, class T2>
//class IfThenElse<true, T1, T2>
//{
//public:
//	typedef T1 ResultT;
//};
//
//template<class T1, class T2>
//class IfThenElse<false, T1, T2>
//{
//public:
//	typedef T2 ResultT;
//};
//
//template<class T1, class T2>
//class ReturnValueTrait
//{
//public:
//	typedef typename IfThenElse<(sizeof(T1) > sizeof(T2)), T1, T2>::ResultT ResultT;
//};
//
////因为int和float类型所占的字节相同，所以无法通过比较大小来判断类型的精度，需要偏特化  
//template<>
//class ReturnValueTrait<float, int>
//{
//public:
//	typedef float ResultT;
//};
//
//template<>
//class ReturnValueTrait<int, float>
//{
//public:
//	typedef float ResultT;
//};
//
//template<class t1, class t2>
//typename ReturnValueTrait<t1, t2>::ResultT Add(t1 lhs, t2 rhs)
//{
//
//	return lhs + rhs;
//}
//
//
//int main(){
//	cout << Add(1,2) << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//template<bool T,class T1,class T2>
//class Solution;
//
//template<class T1,class T2>
//class Solution<true, T1, T2>{
//public:
//	typedef T1 resultT;
//};
//
//template<class T1,class T2>
//class Solution<false, T1, T2>{
//public:
//	typedef T2 resultT;
//};
//
//template<typename T1, typename T2>
//class Returnvalue{
//public:
//	typedef typename Solution<(sizeof(T1)>sizeof(T2)), T1, T2 > ::result resultT;
//};
//
//
//template<typename T1, typename T2>
//typename Returnvalue<T1, T2>::resultT Add(T1 a,T1 b){
//	return a + b;
//}
//
//int main(){
//	cout << Add(1, 2) << endl;
//}


#include<iostream>
using namespace std;

template<bool T,class T1,class T2>
class solutoin;

template<class T1,class T2>
class solutoin<true, T1, T2>{
public:
	typedef T1 ResultT;
};

template<class T1,class T2>
class solutoin<false, T1, T2>
{
public:
	typedef T2 ResultT;
};

template<class T1, class T2>
class Returnvalue{
public:
	typedef typename solutoin<(sizeof(T1)>sizeof(T2)), T1, T2 >::ResultT ResultT;
};

template<class T1,class T2>
typename Returnvalue<T1, T2>::ResultT Add(const T1& a, const T2& b){
	return a + b;
}

int main(){
	cout << Add(1, 2) << endl;
	system("pause");
	return 0;
}