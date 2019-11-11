typedef struct	s_matrix
{
	float**		tab;
	int			width;
	int			height;
}				t_matrix;


t_matrix	init_matrix(int width, int height);
void		free_matrix(t_matrix* matrix);

t_matrix	read_matrix();
void		print_matrix(const t_matrix* matrix);
