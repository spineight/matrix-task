#include "matrix.h"
#include "test_helpers.h"

#include <gtest/gtest.h>

TEST(traits_test, member_types) {
  EXPECT_TRUE((std::is_same_v<element, matrix<element>::value_type>));

  EXPECT_TRUE((std::is_same_v<element&, matrix<element>::reference>));
  EXPECT_TRUE((std::is_same_v<const element&, matrix<element>::const_reference>));

  EXPECT_TRUE((std::is_same_v<element*, matrix<element>::pointer>));
  EXPECT_TRUE((std::is_same_v<const element*, matrix<element>::const_pointer>));

  EXPECT_TRUE((std::is_same_v<element*, matrix<element>::iterator>));
  EXPECT_TRUE((std::is_same_v<const element*, matrix<element>::const_iterator>));

  EXPECT_TRUE((std::is_same_v<element*, matrix<element>::row_iterator>));
  EXPECT_TRUE((std::is_same_v<const element*, matrix<element>::const_row_iterator>));
}

TEST(traits_test, iterator_categories) {
  EXPECT_TRUE(std::contiguous_iterator<matrix<element>::iterator>);
  EXPECT_TRUE(std::contiguous_iterator<matrix<element>::const_iterator>);

  EXPECT_TRUE(std::contiguous_iterator<matrix<element>::row_iterator>);
  EXPECT_TRUE(std::contiguous_iterator<matrix<element>::const_row_iterator>);

  EXPECT_TRUE(std::random_access_iterator<matrix<element>::col_iterator>);
  EXPECT_TRUE(std::random_access_iterator<matrix<element>::const_col_iterator>);
}

TEST(traits_test, range_categories) {
  EXPECT_TRUE(std::ranges::contiguous_range<matrix<element>>);
  EXPECT_TRUE(std::ranges::contiguous_range<const matrix<element>>);
}

TEST(traits_test, col_iterator_member_types) {
  using col_iterator = matrix<element>::col_iterator;
  using const_col_iterator = matrix<element>::const_col_iterator;

  EXPECT_TRUE((std::is_same_v<element, col_iterator::value_type>));
  EXPECT_TRUE((std::is_same_v<element&, col_iterator::reference>));
  EXPECT_TRUE((std::is_same_v<element*, col_iterator::pointer>));
  EXPECT_TRUE((std::is_same_v<std::ptrdiff_t, col_iterator::difference_type>));
  EXPECT_TRUE((std::is_same_v<std::random_access_iterator_tag, col_iterator::iterator_category>));

  EXPECT_TRUE((std::is_same_v<element, const_col_iterator::value_type>));
  EXPECT_TRUE((std::is_same_v<const element&, const_col_iterator::reference>));
  EXPECT_TRUE((std::is_same_v<const element*, const_col_iterator::pointer>));
  EXPECT_TRUE((std::is_same_v<std::ptrdiff_t, const_col_iterator::difference_type>));
  EXPECT_TRUE((std::is_same_v<std::random_access_iterator_tag, const_col_iterator::iterator_category>));
}

TEST(traits_test, iterator_triviality) {
  EXPECT_TRUE(std::is_trivial_v<matrix<element>::iterator>);
  EXPECT_TRUE(std::is_trivial_v<matrix<element>::const_iterator>);

  EXPECT_TRUE(std::is_trivial_v<matrix<element>::row_iterator>);
  EXPECT_TRUE(std::is_trivial_v<matrix<element>::const_row_iterator>);

  EXPECT_TRUE(std::is_trivial_v<matrix<element>::col_iterator>);
  EXPECT_TRUE(std::is_trivial_v<matrix<element>::const_col_iterator>);
}
