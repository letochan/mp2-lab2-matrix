#include "utmatrix.h" 

#include <gtest.h> 

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 100));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> M(3);
	M[1][1] = 4;
	TMatrix<int> M1(M);
	EXPECT_EQ(4, M1[1][1]);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> M(3);
	M[1][1] = 4;
	TMatrix<int> M1(M);
	M1[1][1] = 5;
	EXPECT_NE(M, M1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> M(4);
	EXPECT_EQ(4, M.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> M(4);
	M[1][1] = 4;
	EXPECT_EQ(4, M[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> M(5);
	ASSERT_ANY_THROW(M[-1][1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> M(5);
	ASSERT_ANY_THROW(M[MAX_MATRIX_SIZE + 1][1]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> M(3);
	M[1][1] = 2;
	ASSERT_NO_THROW(M = M);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	int size = 3;
	TMatrix<int> M(size), M1(size);
	M[1][1] = 1;
	ASSERT_NO_THROW(M1 = M);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> M(3), M1(5);
	M[1][1] = 2;
	M1[2][1] = 1;
	M1 = M;
	EXPECT_EQ(M1.GetSize(), M.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> M(3), M1(4);
	M[1][1] = 1;
	ASSERT_NO_THROW(M1 = M);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> M(3), M1(3);
	M[1][1] = 1;
	M1[1][1] = 1;
	EXPECT_EQ(M, M1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> M(3), M1(3);
	M[1][1] = 1;
	EXPECT_EQ(M, M);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> M(3), M1(5);
	M[1][1] = 1;
	M1[1][1] = 1;
	EXPECT_NE(M, M1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	int size = 2;
	TMatrix<int> M(size), M1(size), M2(size);
	M[0][0] = 5;
	M[0][1] = 3;
	M[1][1] = 1;
	// (5 3) 
	// M = (0 1) 
	M1[0][0] = 2;
	M1[0][1] = 4;
	M1[1][1] = 6;
	// (2 4) 
	//M1 = (0 6) 
	M2[0][0] = 7;
	M2[0][1] = 7;
	M2[1][1] = 7;
	// (7 7) 
	//M1 + M = (0 7) 
	EXPECT_EQ(M1 + M, M2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> M(3), M1(5);
	M[1][1] = 1;
	M1[1][1] = 2;
	ASSERT_ANY_THROW(M + M1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	int size = 2;
	TMatrix<int> M(size), M1(size), M2(size);
	M[0][0] = 5;
	M[0][1] = 4;
	M[1][0] = 0;
	M[1][1] = 6;
	// (5 4) 
	// M = (0 6) 
	M1[0][0] = 2;
	M1[0][1] = 3;
	M1[1][0] = 0;
	M1[1][1] = 1;
	// (2 3) 
	//M1 = (0 1) 
	M2[0][0] = 3;
	M2[0][1] = 1;
	M2[1][1] = 5;
	// (3 1) 
	//M1 - M = (0 5) 
	EXPECT_EQ(M - M1, M2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> M(3), M1(5);
	M[1][1] = 1;
	M1[1][1] = 2;
	ASSERT_ANY_THROW(M - M1);
}
