//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/quat.hpp>
#include <mon/test_case.hpp>

#include <cmath>
#include <tue/math.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace {
using namespace tue;

CONST_OR_CONSTEXPR dvec3 dv32(2.2, 2.4, 2.6);

CONST_OR_CONSTEXPR fquat fq1(1.1f, 1.2f, 1.3f, 1.4f);

CONST_OR_CONSTEXPR dquat dq1(1.1, 1.2, 1.3, 1.4);
CONST_OR_CONSTEXPR dquat dq2(2.2, 2.4, 2.6, 2.8);

CONST_OR_CONSTEXPR quat<int> iq1(111, 222, 333, 444);

TEST_CASE(default_constructor) {
  fquat q;
  unused(q);
}

TEST_CASE(scalar_component_constructor) {
  CONST_OR_CONSTEXPR fquat q(1.1f, 2.2f, 3.3f, 4.4f);
  test_assert(q[0] == 1.1f);
  test_assert(q[1] == 2.2f);
  test_assert(q[2] == 3.3f);
  test_assert(q[3] == 4.4f);
}

TEST_CASE(vector_component_constructor) {
  CONST_OR_CONSTEXPR fquat q(fvec3(1.1f, 2.2f, 3.3f), 4.4f);
  test_assert(q[0] == 1.1f);
  test_assert(q[1] == 2.2f);
  test_assert(q[2] == 3.3f);
  test_assert(q[3] == 4.4f);
}

TEST_CASE(explicit_conversion_constructor) {
  CONST_OR_CONSTEXPR fquat q(dq1);
  test_assert(q[0] == static_cast<float>(dq1[0]));
  test_assert(q[1] == static_cast<float>(dq1[1]));
  test_assert(q[2] == static_cast<float>(dq1[2]));
  test_assert(q[3] == static_cast<float>(dq1[3]));
}

TEST_CASE(implicit_conversion_constructor) {
  CONST_OR_CONSTEXPR dquat q = fq1;
  test_assert(q[0] == static_cast<double>(fq1[0]));
  test_assert(q[1] == static_cast<double>(fq1[1]));
  test_assert(q[2] == static_cast<double>(fq1[2]));
  test_assert(q[3] == static_cast<double>(fq1[3]));
}

TEST_CASE(identity) {
  CONST_OR_CONSTEXPR auto q = fquat::identity();
  test_assert(q[0] == 0);
  test_assert(q[1] == 0);
  test_assert(q[2] == 0);
  test_assert(q[3] == 1);
}

TEST_CASE(x) {
  CONST_OR_CONSTEXPR float x = fq1.x();
  test_assert(x == fq1[0]);
}

TEST_CASE(set_x) {
  fquat q(1.1f, 1.2f, 1.3f, 1.4f);
  q.set_x(2.1f);
  test_assert(q[0] == 2.1f);
  test_assert(q[1] == 1.2f);
  test_assert(q[2] == 1.3f);
  test_assert(q[3] == 1.4f);
}

TEST_CASE(y) {
  CONST_OR_CONSTEXPR float y = fq1.y();
  test_assert(y == fq1[1]);
}

TEST_CASE(set_y) {
  fquat q(1.1f, 1.2f, 1.3f, 1.4f);
  q.set_y(2.2f);
  test_assert(q[0] == 1.1f);
  test_assert(q[1] == 2.2f);
  test_assert(q[2] == 1.3f);
  test_assert(q[3] == 1.4f);
}

TEST_CASE(z) {
  CONST_OR_CONSTEXPR float z = fq1.z();
  test_assert(z == fq1[2]);
}

TEST_CASE(set_z) {
  fquat q(1.1f, 1.2f, 1.3f, 1.4f);
  q.set_z(2.3f);
  test_assert(q[0] == 1.1f);
  test_assert(q[1] == 1.2f);
  test_assert(q[2] == 2.3f);
  test_assert(q[3] == 1.4f);
}

TEST_CASE(w) {
  CONST_OR_CONSTEXPR float w = fq1.w();
  test_assert(w == fq1[3]);
}

TEST_CASE(set_w) {
  fquat q(1.1f, 1.2f, 1.3f, 1.4f);
  q.set_w(2.4f);
  test_assert(q[0] == 1.1f);
  test_assert(q[1] == 1.2f);
  test_assert(q[2] == 1.3f);
  test_assert(q[3] == 2.4f);
}

TEST_CASE(v) {
  CONST_OR_CONSTEXPR fvec3 v = fq1.v();
  test_assert(v == fvec3(fq1[0], fq1[1], fq1[2]));
}

TEST_CASE(set_v) {
  fquat q1(1.1f, 1.2f, 1.3f, 1.4f);
  q1.set_v(2.1f, 2.2f, 2.3f);
  test_assert(q1[0] == 2.1f);
  test_assert(q1[1] == 2.2f);
  test_assert(q1[2] == 2.3f);
  test_assert(q1[3] == 1.4f);

  fquat q2(1.1f, 1.2f, 1.3f, 1.4f);
  q2.set_v(fvec3(2.1f, 2.2f, 2.3f));
  test_assert(q2[0] == 2.1f);
  test_assert(q2[1] == 2.2f);
  test_assert(q2[2] == 2.3f);
  test_assert(q2[3] == 1.4f);
}

TEST_CASE(s) {
  CONST_OR_CONSTEXPR float s = fq1.s();
  test_assert(s == fq1[3]);
}

TEST_CASE(set_s) {
  fquat q(1.1f, 1.2f, 1.3f, 1.4f);
  q.set_s(2.4f);
  test_assert(q[0] == 1.1f);
  test_assert(q[1] == 1.2f);
  test_assert(q[2] == 1.3f);
  test_assert(q[3] == 2.4f);
}

TEST_CASE(data) {
  fquat q = fq1;
  float* data = q.data();
  test_assert(static_cast<void*>(data) == static_cast<void*>(&q));

  const fquat& cq = q;
  const float* cdata = cq.data();
  test_assert(cdata == data);
}

TEST_CASE(subscript_operator) {
  CONST_OR_CONSTEXPR fquat ceq(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR float ceq0 = ceq[0];
  CONST_OR_CONSTEXPR float ceq1 = ceq[1];
  CONST_OR_CONSTEXPR float ceq2 = ceq[2];
  CONST_OR_CONSTEXPR float ceq3 = ceq[3];
  test_assert(ceq0 == 1.1f);
  test_assert(ceq1 == 2.2f);
  test_assert(ceq2 == 3.3f);
  test_assert(ceq3 == 4.4f);

  fquat q = ceq;
  float& q0 = q[0];
  float& q1 = q[1];
  float& q2 = q[2];
  float& q3 = q[3];
  test_assert(static_cast<void*>(&q0) == static_cast<void*>(&q));
  test_assert(&q1 == &q0 + 1);
  test_assert(&q2 == &q0 + 2);
  test_assert(&q3 == &q0 + 3);

  const fquat& cq = q;
  const float& cq0 = cq[0];
  const float& cq1 = cq[1];
  const float& cq2 = cq[2];
  const float& cq3 = cq[3];
  test_assert(&cq0 == &q0);
  test_assert(&cq1 == &q1);
  test_assert(&cq2 == &q2);
  test_assert(&cq3 == &q3);
}

TEST_CASE(multiplication_operator) {
  CONST_OR_CONSTEXPR auto q = fq1 * dq2;
  test_assert(q.v() == fq1.s()*dq2.v() + dq2.s()*fq1.v()
      + math::cross(fq1.v(), dq2.v()));
  test_assert(q.s() == fq1.s() * dq2.s() - math::dot(fq1.v(), dq2.v()));

  CONST_OR_CONSTEXPR dvec3 v = dv32 * fq1;
  test_assert(v == (fq1 * dquat(dv32, 0) * math::conjugate(fq1)).v());
}

TEST_CASE(equality_operator) {
  CONST_OR_CONSTEXPR fquat q1(1.0f, 2.0f, 3.0f, 4.0f);
  CONST_OR_CONSTEXPR quat<int> q2(1, 2, 3, 4);
  CONST_OR_CONSTEXPR quat<int> q3(0, 2, 3, 4);
  CONST_OR_CONSTEXPR quat<int> q4(1, 0, 3, 4);
  CONST_OR_CONSTEXPR quat<int> q5(1, 2, 0, 4);
  CONST_OR_CONSTEXPR quat<int> q6(1, 2, 3, 0);
  CONST_OR_CONSTEXPR bool result1 = (q1 == q2);
  CONST_OR_CONSTEXPR bool result2 = (q1 == q3);
  CONST_OR_CONSTEXPR bool result3 = (q1 == q4);
  CONST_OR_CONSTEXPR bool result4 = (q1 == q5);
  CONST_OR_CONSTEXPR bool result5 = (q1 == q6);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
  test_assert(result4 == false);
  test_assert(result5 == false);
}

TEST_CASE(inequality_operator) {
  CONST_OR_CONSTEXPR fquat q1(1.0f, 2.0f, 3.0f, 4.0f);
  CONST_OR_CONSTEXPR quat<int> q2(1, 2, 3, 4);
  CONST_OR_CONSTEXPR quat<int> q3(0, 2, 3, 4);
  CONST_OR_CONSTEXPR quat<int> q4(1, 0, 3, 4);
  CONST_OR_CONSTEXPR quat<int> q5(1, 2, 0, 4);
  CONST_OR_CONSTEXPR quat<int> q6(1, 2, 3, 0);
  CONST_OR_CONSTEXPR bool result1 = (q1 != q2);
  CONST_OR_CONSTEXPR bool result2 = (q1 != q3);
  CONST_OR_CONSTEXPR bool result3 = (q1 != q4);
  CONST_OR_CONSTEXPR bool result4 = (q1 != q5);
  CONST_OR_CONSTEXPR bool result5 = (q1 != q6);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
  test_assert(result4 == true);
  test_assert(result5 == true);
}

TEST_CASE(length2) {
  test_assert(math::length2(fq1)
      == math::length2(fq1[0])
      + math::length2(fq1[1])
      + math::length2(fq1[2])
      + math::length2(fq1[3]));

  test_assert(math::length2(iq1) == math::length2(dquat(iq1)));
}

TEST_CASE(length) {
  test_assert(math::length(fq1) == math::sqrt(math::length2(fq1)));
  test_assert(math::length(iq1) == math::length(dquat(iq1)));
}

TEST_CASE(normalize) {
  const fquat q = math::normalize(fq1);
  test_assert(q[0] == fq1[0] / math::length(fq1));
  test_assert(q[1] == fq1[1] / math::length(fq1));
  test_assert(q[2] == fq1[2] / math::length(fq1));
  test_assert(q[3] == fq1[3] / math::length(fq1));
  test_assert(math::normalize(iq1) == math::normalize(dquat(iq1)));
}

TEST_CASE(conjugate) {
  CONST_OR_CONSTEXPR fquat q = math::conjugate(fq1);
  test_assert(q.v() == -fq1.v());
  test_assert(q.s() == fq1.s());
}

TEST_CASE(rotation_quat_from_axis_angle) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const float w = 4.4f;
  const fvec3 v(x, y, z);
  const fquat q1 = math::rotation_quat(v, w);
  test_assert(q1.v() == v * math::sin(w / 2));
  test_assert(q1.s() == math::cos(w / 2));

  const fquat q2 = math::rotation_quat(x, y, z, w);
  test_assert(q2 == q1);

  const fquat q3 = math::rotation_quat(fvec4(x, y, z, w));
  test_assert(q3 == q1);
}

TEST_CASE(rotation_quat_from_rotation_vec) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const fvec3 v(x, y, z);
  const fquat q1 = math::rotation_quat(v);
  test_assert(q1 == math::rotation_quat(math::axis_angle(v)));

  const fquat q2 = math::rotation_quat(x, y, z);
  test_assert(q2 == q1);
}

TEST_CASE(axis_angle) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const float w = 4.4f;
  const fquat q = math::normalize(fquat(x, y, z, w));
  const fvec4 v = math::axis_angle(q);
  test_assert(v.xyz() == math::normalize(q.v()));
  test_assert(v.w() == 2 * std::acos(q.s()));
}

TEST_CASE(rotation_vec) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const float w = 4.4f;
  const fquat q = math::normalize(fquat(x, y, z, w));
  const fvec3 v = math::rotation_vec(q);
  test_assert(v == math::rotation_vec(math::axis_angle(q)));
}

}
