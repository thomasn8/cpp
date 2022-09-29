#include <iostream>
#include "../vector.hpp"
#include "../container_details.hpp"

class BClass {
public:
    char *l;
    int i;
    BClass():l(nullptr), i(1) {};
    BClass(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~BClass() {
        delete this->l;
        this->l = nullptr;
    };
};

class AClass : public BClass {
public:
    AClass():BClass(){};
    AClass(const BClass* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~AClass() {
        delete this->l;
        this->l = nullptr;
    };
};

int main()
{
	ft::vector<int> v;

 	std::unique_ptr<BClass> k2(new BClass(3));
    std::unique_ptr<BClass> k3(new BClass(4));
    std::unique_ptr<BClass> k4(new BClass(-1));
    ft::vector<AClass> vv;
    ft::vector<BClass*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }	
	return 0;
}