#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <string>
#include <queue>
#include <list>
#include <vector>
#include <stack>
#include <cmath>
#include <sstream>

/*本程序所说的式项是指表达式的最小单元（可以是一个数、一个运算符或一个括号），不是指“多项式”的项
前缀g用于避免发生名字冲突*/

class Calculator
{
private:
    //式项的类型
    enum Symbol
    {
        g_lbracket, g_rbracket,   //level6
        g_plus, g_minus,  //level5
        g_multiply, g_divide, g_mod,   //level4
        g_arcsin, g_arccos, g_arctan, g_sin, g_cos, g_tan,
        g_ln, g_log, g_positive, g_negative, //level3
        g_power, g_root, g_sqrt,   //level2
        g_factorial, //level1
        g_num, g_pi, g_e, g_Ans,    //level0
        g_error  //代表错误
    };


    /*用于储存一个式项的类
    根据sym判断是数还是运算符，如果是数则val为代表该数值的数值*/
    struct Item
    {
        Symbol sym = g_lbracket;
        double val = 0;

        Item(Symbol Sym = g_lbracket,double Val = 0):sym(Sym),val(Val) {}
        Item(const Item &I):sym(I.sym),val(I.val){}
        Item& operator=(const Item &I)
        {
            sym = I.sym;
            val = I.val;
            return *this;
        }
        ~Item() = default;
    };

    /*符号表的元素类型，sym代表用字母字符串代表的运算符(如sin)或特殊的数(如圆周率pi)，
    str代表相应的字符串*/
    struct symbol_string
    {
        Symbol sym;
        std::string str;

        symbol_string(Symbol Sym, std::string Str):sym(Sym),str(Str){}
        symbol_string(const symbol_string &sym_str):sym(sym_str.sym),str(sym_str.str){}
        symbol_string& operator=(const symbol_string &sym_str)
        {
            sym = sym_str.sym;
            str = sym_str.str;
            return *this;
        }
        ~symbol_string() = default;
    };

    //符号表，用于识别用字母字符串代表的运算符或特殊的数
    std::vector<symbol_string> svec
    {
        symbol_string(g_Ans, "Ans"),
        symbol_string(g_arccos, "arccos"),
        symbol_string(g_arcsin, "arcsin"),
        symbol_string(g_arctan, "arctan"),
        symbol_string(g_cos, "cos"),
        symbol_string(g_e, "e"),
        symbol_string(g_ln, "ln"),
        symbol_string(g_log, "log"),
        symbol_string(g_pi, "pi"),
        symbol_string(g_root, "root"),
        symbol_string(g_sin, "sin"),
        symbol_string(g_sqrt, "sqrt"),
        symbol_string(g_tan, "tan")
    };

    const double pi = asin(1) * 2;  //圆周率

    const double e = exp(1);    //自然常数

    double Ans = 0.0;   //保存上一次计算的结果

    //角度转换成弧度
    double DegreeToRadian(double r)
    {
        return r * pi / 180.0;
    }

    //梯度转换成弧度
    double GradientToRadian(double r)
    {
        return DegreeToRadian(r * 9 / 10);
    }

    //用于代表式项的运算类型
    enum ArithmeticType
    {
        right_combination,  //右结合运算符(如sin、左括号)
        no_type,            //数，没有运算类型
        left_combination,   //左结合单目运算符(如！、右括号)
        binocular           //双单目运算符
    };

    //返回运算符s的运算类型
    ArithmeticType getSymArithmeticType(Symbol s);

    //返回运算符s的优先级(详见Symbol的定义。 数、括号、错误的优先级没有意义)
    int getOperatorLevel(Symbol s);

    //输出式项g，用于调试
    void showItem(const Item &i);

    //输出后缀表达式postfix_exp，用于调试
    void showRPN(std::list<Item> &postfix_exp);

    /*从字符串输入流sin中读取一个字母字符串,并查找该字母字符串代表的运算符或特殊的数
    若查找成功，则返回相应的运算符或数的类型
    否则返回g_error*/
    Symbol getsym(std::istringstream &sin);

    /*从字符串输入流sin中读取一个非字母的单字符所表示的运算符
    g_front代表上一个式项的类型,用于区分加号和正号、减号和负号*/
    Symbol getoperator(std::istringstream &sin, Symbol g_front);

    /*从字符串输入流sin中读取一个式项到item
    g_front代表上一个式项的类型，用于检测表达式是否有格式错误
    若读取成功且没有格式错误，则返回空字符串
    否则返回含有出错信息的字符串*/
    std::string getItem(std::istringstream &sin, Item &item, Symbol g_front);

    /*将中缀表达式infix_exp转换成后缀表达式postfix_exp
    若转换成功，则返回空字符串
    否则返回含有出错信息的字符串*/
    std::string changeintoRPN(std::string infix_exp, std::list<Item> &postfix_exp);

    /*执行运算，操作数在运算栈Computing_stack中，运算符由s表示，
    运算结果压人运算栈Computing_stack
    若没有算术错误，则返回true
    否则返回false*/
    bool calculate_term(std::stack<double,std::list<double>> &Computing_stack, Symbol s);

    bool garcsin(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool garccos(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool garctan(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool gsin(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool gcos(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool gtan(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool gpower(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool groot(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);
    bool gfactorial(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack);

protected:
    //用于代表角的度量单位
    enum Angle
    {
        degree,     //角度
        radian,     //弧度
        gradient    //梯度
    };

    Angle a = radian; //代表运算时使用的角的度量单位

    int significant_figures = 10;   //代表运算后结果应保留的有效数字

public:
    Calculator() = default;
    ~Calculator() = default;

    /*对中缀表达式infix_exp求值
    若成功，则返回以字符串表示的求值结果
    否则返回以字符串表示的出错信息*/
    std::string calculate_exp(std::string infix_exp);

	void setDegree()
	{
		a = degree;
	}

	void setRadian()
	{
		a = radian;
	}

	void setGradient()
	{
		a = gradient;
	}

};

#endif // CALCULATOR_H_INCLUDED
