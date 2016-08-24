#include "calculator.h"
#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

/*���������s����������
��s���ҽ�ϵ�Ŀ�����(��sin��������), ����right_combination
��s����, ����no_type
��s�����ϵ�Ŀ�����(�磡��������), ����left_combination
��s��˫��Ŀ�����(��+), ����binocular*/
Calculator::ArithmeticType Calculator::getSymArithmeticType(Symbol s)
{
    switch (s)
    {
        case g_arcsin:
        case g_arccos:
        case g_arctan:
        case g_sin:
        case g_cos:
        case g_tan:
        case g_ln:
        case g_log:
        case g_positive:
        case g_negative:
        case g_sqrt:
        case g_lbracket:
            return right_combination;
        case g_num:
        case g_pi:
        case g_e:
        case g_Ans:
            return no_type;
        case g_factorial:
        case g_rbracket:
            return left_combination;
        case g_plus:
        case g_minus:
        case g_multiply:
        case g_divide:
        case g_mod:
        case g_power:
        case g_root:
            return binocular;
        default:
            break;
    }
    return no_type;
}

//���������s�����ȼ�(���Symbol�Ķ��塣 �������š���������ȼ�û������)
int Calculator::getOperatorLevel(Symbol s)
{
    switch (s)
    {
        case g_lbracket:
        case g_rbracket:
            return 6;
        case g_plus:
        case g_minus:
            return 5;
        case g_multiply:
        case g_divide:
        case g_mod:
            return 4;
        case g_arcsin:
        case g_arccos:
        case g_arctan:
        case g_sin:
        case g_cos:
        case g_tan:
        case g_ln:
        case g_log:
        case g_positive:
        case g_negative:
            return 3;
        case g_power:
        case g_root:
        case g_sqrt:
            return 2;
        case g_factorial:
            return 1;
        default:
            return 0;
    }
}

//���ʽ��i�����ڵ���
void Calculator::showItem(const Item &i)
{
    switch (i.sym)
    {
        case g_plus:
        case g_positive:
            cout << '+';
            break;
        case g_minus:
        case g_negative:
            cout << '-';
            break;
        case g_arcsin:
            cout << "arcsin";
            break;
        case g_arccos:
            cout << "arccos";
            break;
        case g_arctan:
            cout << "arctan";
            break;
        case g_sin:
            cout << "sin";
            break;
        case g_cos:
            cout << "cos";
            break;
        case g_tan:
            cout << "tan";
            break;
        case g_multiply:
            cout << '*';
            break;
        case g_divide:
            cout << '/';
            break;
        case g_mod:
            cout << "mod";
            break;
        case g_ln:
            cout << "ln";
            break;
        case g_log:
            cout << "log";
            break;
        case g_power:
            cout<<'^';break;
        case g_root:
            cout << "root";
            break;
        case g_sqrt:
            cout << "sqrt";
            break;
        case g_factorial:
            cout << '!';
            break;
        case g_lbracket:
            cout << '(';
            break;
        case g_rbracket:
            cout << ')';
            break;
        case g_num:
            cout << i.val;
            break;
        case g_pi:
            cout << "pi";
            break;
        case g_e:
            cout << "e";
            break;
        case g_Ans:
            cout << "Ans";
            break;
        case g_error:
            cerr << "showItemError:g_error\n";
            break;
        default:
            cerr << "showItemError\n";
            break;
    }
}

//�����׺���ʽpostfix_exp�����ڵ���
void Calculator::showRPN(std::list<Item> &postfix_exp)
{
    for (const Item &i : postfix_exp)
    {
        showItem(i);
        cout << ' ';
    }
    cout << endl;
}

/*���ַ���������sin�ж�ȡһ����ĸ�ַ���,�����Ҹ���ĸ�ַ����������������������
�����ҳɹ����򷵻���Ӧ�����������������
���򷵻�g_error*/
Calculator::Symbol Calculator::getsym(istringstream &sin)
{
    string s;
    char c;

    //��ȡ��ĸ�ַ�����-1�����ļ�������
    while (sin.peek() !=-1 && isalpha(sin.peek()))
    {
        sin >> c;
        s.push_back(c);
    }

    //�۰����
    int i = 0, k, j = svec.size();
    while (i <= j)
    {
        k = ( i + j ) / 2;
        if (s < svec[k].str)
        {
            j = k - 1;
        }
        else if (s > svec[k].str)
        {
            i = k+ 1;
        }
        else if (s == svec[k].str)
        {
            return svec[k].sym;
        }
    }

    return g_error;
}

/*���ַ���������sin�ж�ȡһ������ĸ�ĵ��ַ�����ʾ�������
g_front������һ��ʽ�������,�������ּӺź����š����ź͸���*/
Calculator::Symbol Calculator::getoperator(istringstream &sin, Symbol g_front)
{
    char c;
    sin >> c;
    ArithmeticType a;
    switch (c)
    {
        case '+':
            a = getSymArithmeticType(g_front);
            if (a == no_type || a == left_combination)
            {
                //��'+'��ߵ������������������������ǼӺ�
                return g_plus;
            }
            else
            {
                //�����������
                return g_positive;
            }
        case '-':
            a = getSymArithmeticType(g_front);
            if (a == no_type || a == left_combination)
            {
                //��'-'��ߵ������������������������Ǽ���
                return g_minus;
            }
            else
            {
                //���������
                return g_negative;
            }
        case '*':
            return g_multiply;
        case '/':
            return g_divide;
        case '%':
            return g_mod;
        case '^':
            return g_power;
        case '!':
            return g_factorial;
        case '(':
            return g_lbracket;
        case ')':
            return g_rbracket;
        default:
            return g_error;
            break;
    }
}

/*���ַ���������sin�ж�ȡһ��ʽ�item
g_front������һ��ʽ������ͣ����ڼ����ʽ�Ƿ��и�ʽ����
����ȡ�ɹ���û�и�ʽ�����򷵻ؿ��ַ���
���򷵻غ��г�����Ϣ���ַ���*/
string Calculator::getItem(istringstream &sin, Item &item, Symbol g_front)
{
    char c = sin.peek();

    //�����ո�-1�����ļ�������
    while (c !=-1 && isspace(c))
    {
        sin.get();
        c = sin.peek();
    }

    if (c != -1)
    {
        if (isdigit(c))
        {
            //�����ж�ȡһ��ʮ�������������Կ�ѧ��������ʾ��
            if (sin >> item.val) //�ж��������ֵ�Ƿ��������ֵ��Χ��double����
            {
                item.sym = g_num;
            }
            else
            {
                return "overflow\n";
            }
        }
        else if (isalpha(c))
        {
            //�����ж�ȡһ����ĸ�ַ������õ�����ĸ�ַ������������
            item.sym = getsym(sin);
            //��g.sym����һ������������򽫶�Ӧ����ֵ����g.val
            switch (item.sym)
            {
                case g_e:
                    item.val = e;
                    break;
                case g_pi:
                    item.val = pi;
                    break;
                case g_Ans:
                    item.val = Ans;
                    break;
                default:
                    break;
            }
        }
        else
        {
            //�����ж�ȡһ������ĸ�ĵ��ַ�����ʾ�������
            item.sym = getoperator(sin, g_front);
        }
    }

    //����ȡ���������﷨������Ϣ
    if (item.sym == g_error)
    {
        return "Syntax ERROR\n";
    }
    else
    {
        return "";
    }
}

/*����׺���ʽinfix_expת���ɺ�׺���ʽpostfix_exp
��ת���ɹ����򷵻ؿ��ַ���
���򷵻غ��г�����Ϣ���ַ���*/
string Calculator::changeintoRPN(string infix_exp, list<Item> &postfix_exp)
{
    postfix_exp.clear();
    stack<Symbol, list<Symbol>> sym_stack; //�������ջ
    sym_stack.push(g_lbracket); //ѹ��һ�������ŵ�����ջ����Ϊ���ʽ��ʼ
    infix_exp.push_back(')'); //����׺���ʽinfix_expβ����������ţ���Ϊ���ʽ����
    istringstream sin(infix_exp);   /*����׺���ʽinfix_exp�󶨵��ַ���������sin��
                                    ���ڱ�ݵض�ȡ��׺���ʽinfix_exp*/
    Symbol g_front = g_lbracket;   //��¼��һ��ʽ������ͣ����ڸ���������
    Item item;    //���ڴ��浱ǰ��ȡ��ʽ��

    //ͨ����ȡ�ַ���������sin����ȡ��׺���ʽinfix_exp��-1�����ļ�������
    while (sin.peek() != -1)
    {
        string exc; //���ڴ����쳣��Ϣ

        //����ȡ��ʱ�����쳣�򷵻��쳣��Ϣ
        if ( (exc = getItem(sin, item, g_front)) != "")
        {
            return exc;
        }

        //�ж��Ƿ����﷨����
        ArithmeticType front_arith = getSymArithmeticType(g_front); //��¼��һ��ʽ����������
        ArithmeticType current_arith = getSymArithmeticType(item.sym); //��¼��ǰʽ����������
        if
        (
            //�ҽ�ϵ�Ŀ��������ұ߲��������ϵ�Ŀ�������˫Ŀ�����
            (front_arith == right_combination
                && (current_arith == left_combination || current_arith == binocular))

            //�����ұ߲������ҽ�ϵ�Ŀ���������
            || (front_arith == no_type
                && (current_arith == right_combination || current_arith == no_type))

            //���ϵ�Ŀ������ұ߲������ҽ�ϵ�Ŀ���������
            || (front_arith == left_combination
                && (current_arith == right_combination || current_arith == no_type))

            //˫Ŀ������ұ߲��������ϵ�Ŀ�������˫Ŀ�����
            || (front_arith == binocular
                && (current_arith == left_combination || current_arith == binocular))
        )
        {
            return "Syntax ERROR\n";
        }

        //�����ȡ����ʽ��item
        if (current_arith == no_type)
        {
            //��ʽ��item����һ��������ֱ���������׺���ʽpostfix_exp��
            postfix_exp.emplace_back(item);
            g_front = item.sym;
        }
        else if (current_arith == right_combination)
        {
            //��ʽ��item�����ҽ�ϵ�Ŀ���������ֱ���������׺���ʽpostfix_exp��
            sym_stack.push(item.sym);
            g_front = item.sym;
        }
        else if (item.sym == g_rbracket)
        {
            /*��ʽ��item���������ţ��򲻶Ͻ�����ջ�еķ��ŵ����������׺���ʽpostfix_exp
            ֱ��ƥ�䵽�����Ż����ջΪ��*/
            while (sym_stack.top() != g_lbracket && ! sym_stack.empty())
            {
                postfix_exp.emplace_back(sym_stack.top());
                sym_stack.pop();
            }

            if (sym_stack.empty())
            {
                //��û��ƥ�䵽�����ţ��򷵻ء���ʧ�����š�
                return "lose left bracket\n";
            }
            else
            {
                //���򵯳�������
                sym_stack.pop();
                g_front = item.sym;
            }
        }
        else
        {
            //��������š����ҽ�ϵ������

            /*ѭ������������ջ��������������ȼ���С�ڵ�ǰ�����item.sym,
            ѭ���壺����ջ��������������������׺���ʽpostfix_exp*/
            while (getOperatorLevel(item.sym) >= getOperatorLevel(sym_stack.top()))
            {
                postfix_exp.emplace_back(sym_stack.top());
                sym_stack.pop();
            }

            sym_stack.push(item.sym);   //����ǰ�����ѹ�˷���ջ
            g_front = item.sym;
        }
    }//��׺���ʽinfix_exp��ȡ����

    /*����׺���ʽinfix_expû���﷨����
    �����ջӦΪ��*/
    if (sym_stack.empty())
    {
        return "";
    }
    else
    {
        //����ջ����������ʣ��
        return "lose right bracket\n";
    }
}

/*ִ�����㣬������������ջComputing_stack�У��������s��ʾ��
������ѹ������ջComputing_stack
��û�����������򷵻�true
���򷵻�false*/
bool Calculator::calculate_term(stack<double,list<double>> &Computing_stack, Symbol s)
{
    double o1, o2;
    if (getSymArithmeticType(s) == binocular)
    {
        o2 = Computing_stack.top();
        Computing_stack.pop();
        o1 = Computing_stack.top();
        Computing_stack.pop();
    }
    else
    {
        o1 = Computing_stack.top();
        Computing_stack.pop();
    }
    switch (s)
    {
        case g_plus:
            {
                Computing_stack.push(o1 + o2);
                return true;
            }
        case g_minus:
            {
                Computing_stack.push(o1 - o2);
                return true;
            }
        case g_arcsin:
            return garcsin(o1, o2, Computing_stack);
        case g_arccos:
            return garccos(o1, o2, Computing_stack);
        case g_arctan:
            return garctan(o1, o2, Computing_stack);
        case g_sin:
            return gsin(o1, o2, Computing_stack);
        case g_cos:
            return gcos(o1, o2, Computing_stack);
        case g_tan:
            return gtan(o1, o2, Computing_stack);
        case g_multiply:
            {
                Computing_stack.push(o1*o2);
                return true;
            }
        case g_divide:
            if (o2 != 0.0)
            {
                Computing_stack.push(o1 / o2);
                return true;
            }
            else
            {
                return false;
            }
        case g_mod:
            if (o2 != 0.0)
            {
                Computing_stack.push(fmod(o1, o2));
                return true;
            }
            else
            {
                return false;
            }
        case g_ln:
            if (o1 > 0.0)
            {
                Computing_stack.push(log(o1));
                return true;
            }
            else
            {
                return false;
            }
        case g_log:
            if (o1 > 0.0)
            {
                Computing_stack.push(log10(o1));
                return true;
            }
            else
            {
                return false;
            }
        case g_positive:
            {
                Computing_stack.push(o1);
                return true;
            }
        case g_negative:
            {
                Computing_stack.push(-1 * o1);
                return true;
            }
        case g_power:
            return gpower(o1, o2, Computing_stack);
        case g_root:
            return groot(o1, o2, Computing_stack);
        case g_sqrt:
            if (o1 >= 0)
            {
                Computing_stack.push(sqrt(o1));
                return true;
            }
            else
            {
                return false;
            }
        case g_factorial:
            return gfactorial(o1, o2, Computing_stack);
        default: return false;
    }
    return true;
}

bool Calculator::garcsin(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    if (o1 >= -1.0 && o1 <= 1.0)
    {
        double d = asin(o1);
        if (a == degree)
        {
            d = DegreeToRadian(d);
        }
        else if (a == gradient)
        {
            d = GradientToRadian(d);
        }
        Computing_stack.push(d);
        return true;
    }
    else
    {
        return false;
    }
}

bool Calculator::garccos(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    if ( o1 >= -1.0 && o1 <= 1.0)
    {
        double d = acos(o1);
        if (a == degree)
        {
            d = DegreeToRadian(d);
        }
        else if (a == gradient)
        {
            d = GradientToRadian(d);
        }
        Computing_stack.push(d);
        return true;
    }
    else
    {
        return false;
    }
}

bool Calculator::garctan(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = atan(o1);
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }
    Computing_stack.push(d);
    return true;
}

bool Calculator::gsin(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = o1;
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }
    Computing_stack.push(sin(d));
    return true;
}

bool Calculator::gcos(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = o1;
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }
    Computing_stack.push(cos(d));
    return true;
}

bool Calculator::gtan(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d = o1;
    if (a == degree)
    {
        d = DegreeToRadian(d);
    }
    else if (a == gradient)
    {
        d = GradientToRadian(d);
    }

    if (fabs(fmod(d, pi)) != pi / 2)
    {
        Computing_stack.push(tan(d));
        return true;
    }
    else
    {
        return false;
    }
}

bool Calculator::gpower(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d;
    if ((o1 == 0 && o2 <= 0) || (o1 < 0 && modf(o2, &d) == 0.0))
    {
        return false;
    }
    else
    {
        Computing_stack.push(pow(o1, o2));
        return true;
    }
}

bool Calculator::groot(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d;
    o1 = 1.0 / o1;
    if ((o2 == 0 && o1 <= 0) || (o2 < 0 && modf(o1, &d) != 0.0))
    {
        return false;
    }
    else
    {
        Computing_stack.push(pow(o2, o1));
        return true;
    }
}

bool Calculator::gfactorial(double o1, double o2, std::stack<double,std::list<double>> &Computing_stack)
{
    double d;
    if (modf(o1, &d) == 0.0 && o1 >= 0)
    {
        int sum = 1;
        for(int i = 2; i <= o1; ++i)
        {
            sum *= i;
            if (sum <= 0)
            {
                return false;
            }
        }
        Computing_stack.push(sum);
        return true;
    }
    else
    {
        return false;
    }
}

/*����׺���ʽinfix_exp��ֵ
���ɹ����򷵻����ַ�����ʾ����ֵ���
���򷵻����ַ�����ʾ�ĳ�����Ϣ*/
string Calculator::calculate_exp(string infix_exp)
{
    list<Item> postfix_exp;
    string cs(changeintoRPN(infix_exp, postfix_exp));
    //showRPN(postfix_exp);

    if (!(cs == ""))
    {
        //����׺���ʽת����׺���ʽʧ�ܣ��򷵻س�����Ϣ
        return cs;
    }

    stack<double, list<double>> Computing_stack;
    for (const Item &item : postfix_exp)
    {
        if (getSymArithmeticType(item.sym) == no_type)
        {
            Computing_stack.push(item.val);
        }
        else
        {
            if (calculate_term(Computing_stack, item.sym) == false)
            {
                return "Math ERROR\n";
            }
        }
    }
    Ans = Computing_stack.top();
    ostringstream sout;
    sout << setprecision(significant_figures) << Ans;
    return sout.str();
}
