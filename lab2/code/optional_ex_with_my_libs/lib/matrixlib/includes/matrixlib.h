#ifndef MATRIX_LIB_H
# define MATRIX_LIB_H


typedef struct	s_matrix
{
	int**		tab;
	int			width;
	int			height;
}				t_matrix;


t_matrix*	new_matrix(int width, int height);
t_matrix*	copy_matrix(const t_matrix* other);
void		free_matrix(t_matrix** matrix);

t_matrix*	read_matrix();
void		print_matrix(const t_matrix* matrix);

#endif
