# ifndef HELLO_WORLD_H
# define HELLO_WORLD_H
// 在头文件使用extern关键字声明对象，使该对象能在多个文件中被使用
// 一个对象的声明可以有很多次，但定义只能有一次（一般应在各个文件中而非头文件中定义）
// 声明const常量j
extern const int j;
// 声明函数return_a
extern int return_a( int a );
// 定义constexpr函数
constexpr int cterfunc() { return 42; }


extern int chapter1to2( double b, int m, int l, int j );
extern int chapter3();
extern int chapter4();
extern int chapter5();
extern int chapter6();
extern int chapter9();

# endif

