#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <string>
#include <queue>
#include <list>
#include <vector>
#include <stack>
#include <cmath>
#include <sstream>

/*��������˵��ʽ����ָ���ʽ����С��Ԫ��������һ������һ���������һ�����ţ�������ָ������ʽ������
ǰ׺g���ڱ��ⷢ�����ֳ�ͻ*/

class Calculator
{
private:
    //ʽ�������
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
        g_error  //�������
    };


    /*���ڴ���һ��ʽ�����
    ����sym�ж�������������������������valΪ�������ֵ����ֵ*/
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

    /*���ű��Ԫ�����ͣ�sym��������ĸ�ַ�������������(��sin)���������(��Բ����pi)��
    str������Ӧ���ַ���*/
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

    //���ű�����ʶ������ĸ�ַ����������������������
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

    const double pi = asin(1) * 2;  //Բ����

    const double e = exp(1);    //��Ȼ����

    double Ans = 0.0;   //������һ�μ���Ľ��

    //�Ƕ�ת���ɻ���
    double DegreeToRadian(double r)
    {
        return r * pi / 180.0;
    }

    //�ݶ�ת���ɻ���
    double GradientToRadian(double r)
    {
        return DegreeToRadian(r * 9 / 10);
    }

    //���ڴ���ʽ�����������
    enum ArithmeticType
    {
        right_combination,  //�ҽ�������(��sin��������)
        no_type,            //����û����������
        left_combination,   //���ϵ�Ŀ�����(�磡��������)
        binocular           //˫��Ŀ�����
    };

    //���������s����������
    ArithmeticType getSymArithmeticType(Symbol s);

    //���������s�����ȼ�(���Symbol�Ķ��塣 �������š���������ȼ�û������)
    int getOperatorLevel(Symbol s);

    //���ʽ��g�����ڵ���
    void showItem(const Item &i);

    //�����׺���ʽpostfix_exp�����ڵ���
    void showRPN(std::list<Item> &postfix_exp);

    /*���ַ���������sin�ж�ȡһ����ĸ�ַ���,�����Ҹ���ĸ�ַ����������������������
    �����ҳɹ����򷵻���Ӧ�����������������
    ���򷵻�g_error*/
    Symbol getsym(std::istringstream &sin);

    /*���ַ���������sin�ж�ȡһ������ĸ�ĵ��ַ�����ʾ�������
    g_front������һ��ʽ�������,�������ּӺź����š����ź͸���*/
    Symbol getoperator(std::istringstream &sin, Symbol g_front);

    /*���ַ���������sin�ж�ȡһ��ʽ�item
    g_front������һ��ʽ������ͣ����ڼ����ʽ�Ƿ��и�ʽ����
    ����ȡ�ɹ���û�и�ʽ�����򷵻ؿ��ַ���
    ���򷵻غ��г�����Ϣ���ַ���*/
    std::string getItem(std::istringstream &sin, Item &item, Symbol g_front);

    /*����׺���ʽinfix_expת���ɺ�׺���ʽpostfix_exp
    ��ת���ɹ����򷵻ؿ��ַ���
    ���򷵻غ��г�����Ϣ���ַ���*/
    std::string changeintoRPN(std::string infix_exp, std::list<Item> &postfix_exp);

    /*ִ�����㣬������������ջComputing_stack�У��������s��ʾ��
    ������ѹ������ջComputing_stack
    ��û�����������򷵻�true
    ���򷵻�false*/
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
    //���ڴ���ǵĶ�����λ
    enum Angle
    {
        degree,     //�Ƕ�
        radian,     //����
        gradient    //�ݶ�
    };

    Angle a = radian; //��������ʱʹ�õĽǵĶ�����λ

    int significant_figures = 10;   //�����������Ӧ��������Ч����

public:
    Calculator() = default;
    ~Calculator() = default;

    /*����׺���ʽinfix_exp��ֵ
    ���ɹ����򷵻����ַ�����ʾ����ֵ���
    ���򷵻����ַ�����ʾ�ĳ�����Ϣ*/
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
