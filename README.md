# Usage
Simply declare your class' properties as ```GSProperty<type>``` :

``` cpp
class Example {
public:
	GSProperty<int> positiveInteger {
                /*initial value*/ 100,
                /*(optional, default doesn't change behaviour) setter*/ [](const int& a) { return (a > 0) ? a : 0; },
                /*(optional, default doesn't change behaviour) getter*/ [](const int& a) { return a; }}; 
									  
	void test() {
		positiveInteger = 2000;
		std::cout << positiveInteger << std::endl;  // 2000
		
		positiveInteger = -100;
		std::cout << positiveInteger << std::endl; // 0, value will be overwritten by our custom setter
	}
};
```
