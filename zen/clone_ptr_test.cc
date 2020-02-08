
#include "gtest/gtest.h"

#include "zen/test_types.hpp"
#include "zen/clone_ptr.hpp"

using namespace zen;

TEST(clone_ptr, CanPassSimpleStructByValue) {
  clone_ptr<point> p1 = make_clonable<point>(1, 2);
  ASSERT_EQ(p1->x, 1);
  ASSERT_EQ(p1->y, 2);
}

