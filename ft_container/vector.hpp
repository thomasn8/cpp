/* 
	Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.
*/

#include <memory>
#include <iostream>

# define RED "\033[0;31m"
# define WHI "\033[0m"

using namespace std;

/* 

default (1)	
explicit vector (const allocator_type& alloc = allocator_type());				-> Constructs an empty container, with no elements.
			alloc
				Allocator object.
				The container keeps and uses an internal copy of this allocator.
				Member type allocator_type is the internal allocator type used by the container, defined in vector as an alias of its second template parameter (Alloc).
				If allocator_type is an instantiation of the default allocator (which has no state), this is not relevant.

*/
namespace ft
{
	template <typename T, typename Alloc = allocator<T> >
	class vector
	{
		public :

		// MEMBER TYPES
			typedef T 											value_type;			// le type de donné inséré dans le container
			typedef unsigned int size_type;											// can represent any non-negative value of difference_type

			typedef allocator<T> 								allocator_type;		// l'allocateur par défault
			typedef typename allocator_type::reference 			reference;			// T& -> Reference to element
			typedef typename allocator_type::const_reference 	const_reference;	// const T& -> Reference to constant element
			typedef	typename allocator_type::pointer 			pointer;			// T* Pointer to element
			typedef	typename allocator_type::const_pointer 		const_pointer;		// cont T* Pointer to constant element
			
			typedef int											difference_type;	// Difference between two pointers (a signed integral type), identical to: iterator_traits<iterator>::difference_type /

			// typedef a random access iterator to value_type	iterator;
			// typedef a random access iterator to const value_type const_iterator;
			// typedef reverse_iterator<iterator> 			reverse_iterator;
			// typedef reverse_iterator<const_iterator> 			const_reverse_iterator;

		// CONSTRUCTEURS/DESTRUCTEUR
			vector<T>(size_type n, const value_type & val) : _n(n)
			{
				// size_type s = this->_difference_type();
				this->_pointer = this->_alloc.allocate(n);					// créer un objet T pour le copier n fois, puis détruit l'objet de base
				this->_first = this->_pointer;
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_pointer, val);
					// this->_alloc.construct(this->_pointer, val);			// utilise l'objet créé pour Construire les instances par copie
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
				cout << "(" << this << " - size) vector created" << endl;	// l'objet initial créé par allocate() est détruit en sortie de fonction
			}
			
			vector<T>() : _n(0)
			{
				this->_first = 0;
				cout << "(" << this << " - default) Null vector created" << endl;
			}

			virtual ~vector<T>()
			{
				cout << "(" << this << " - default) vector destroyed" << endl;
			}

		// SURCHARGES
			T & operator*() const			{ return *this->_first; }
			T * operator&() const			{ return &this->_first; }
			T & operator[](size_type index)	{ return this->_first[index]; }

		// ALLOCATOR
			allocator_type get_allocator() const { return this->_alloc; }
			// for (i=0; i<5; i++)
			// 	myvector.get_allocator().construct(&p[i],i)		->		permet de construire en utilisant un autre Constructeur que celui par copie


			T *				_first;
			T *				_last;
		private :

			allocator_type	_alloc;
			size_type		_n;
			// T *				_first;	
			// T *				_last;	
			T *				_pointer;
			
			size_type _difference_type() const
			{
				return sizeof(T);
			};
	};

	template <typename T>
	ostream	& operator<<(ostream & o, ft::vector<T> const & inst)
	{
		cout << inst._first;
		return o;
	}
}
