#include <stdio.h>
#include <iostream>

int	gl_var = 1;
int	f(){return 2;}

namespace	Foo {
	int	gl_var = 3;
	int	f(){return 4;}
}

namespace	Bar {
	int	gl_var = 5;
	int	f(){return 6;}
}

namespace	Muf = Bar;

int	main(void)
{
	printf("gl_var		%d\n", gl_var);				// 1
	printf("f		%d\n", f());					// 2
	printf("Foo::gl_var	%d\n", Foo::gl_var);		// 3
	printf("Foo:f		%d\n", Foo::f());			// 4
	printf("Bar::gl_var	%d\n", Bar::gl_var);		// 5
	printf("Bar:f		%d\n", Bar::f());			// 6
	printf("Muf::gl_var	%d\n", Muf::gl_var);		// 5
	printf("Muf:f		%d\n", Muf::f());			// 6
	return 0;
}
