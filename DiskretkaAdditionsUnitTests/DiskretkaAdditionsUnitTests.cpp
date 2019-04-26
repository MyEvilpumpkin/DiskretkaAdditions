#include "CppUnitTest.h"
#include "../DiskretkaAdditions/P.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiskretkaAdditionsUnitTests {
	TEST_CLASS(NTests) {
	public:
		TEST_METHOD(N_1_COM_NN_D_Tests) {
			Assert::AreEqual(1, COM_NN_D(N("0"), N("5")), L"Test 1");
			Assert::AreEqual(2, COM_NN_D(N("9"), N("5")), L"Test 2");
			Assert::AreEqual(0, COM_NN_D(N("5"), N("5")), L"Test 3");
		}
		TEST_METHOD(N_2_NZER_N_B_Tests) {
			Assert::AreEqual(false, NZER_N_B(N("0")), L"Test 1");
			Assert::AreEqual(true, NZER_N_B(N("5")), L"Test 2");
		}
		TEST_METHOD(N_3_ADD_1N_N_Tests) {
			Assert::AreEqual(N("1").ToString(), ADD_1N_N(N("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("1000").ToString(), ADD_1N_N(N("999")).ToString(), L"Test 2");
		}
		TEST_METHOD(N_4_ADD_NN_N_Tests) {
			Assert::AreEqual(N("0").ToString(), ADD_NN_N(N("0"), N("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("10").ToString(), ADD_NN_N(N("0"), N("10")).ToString(), L"Test 2");
			Assert::AreEqual(N("100").ToString(), ADD_NN_N(N("100"), N("0")).ToString(), L"Test 3");
			Assert::AreEqual(N("1000").ToString(), ADD_NN_N(N("999"), N("1")).ToString(), L"Test 4");
			Assert::AreEqual(N("10010").ToString(), ADD_NN_N(N("11"), N("9999")).ToString(), L"Test 5");
		}
		TEST_METHOD(N_5_SUB_NN_N_Tests) {
			Assert::AreEqual(N("0").ToString(), SUB_NN_N(N("0"), N("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("10").ToString(), SUB_NN_N(N("10"), N("0")).ToString(), L"Test 2");
			Assert::AreEqual(N("0").ToString(), SUB_NN_N(N("100"), N("100")).ToString(), L"Test 3");
			Assert::AreEqual(N("999").ToString(), SUB_NN_N(N("1000"), N("1")).ToString(), L"Test 4");
			Assert::AreEqual(N("1").ToString(), SUB_NN_N(N("10000"), N("9999")).ToString(), L"Test 5");
		}
		TEST_METHOD(N_6_MUL_ND_N_Tests) {
			Assert::AreEqual(N("0").ToString(), MUL_ND_N(N("0"), 0).ToString(), L"Test 1");
			Assert::AreEqual(N("10").ToString(), MUL_ND_N(N("10"), 1).ToString(), L"Test 2");
			Assert::AreEqual(N("900").ToString(), MUL_ND_N(N("100"), 9).ToString(), L"Test 3");
			Assert::AreEqual(N("0").ToString(), MUL_ND_N(N("1000"), 0).ToString(), L"Test 4");
			Assert::AreEqual(N("50000").ToString(), MUL_ND_N(N("10000"), 5).ToString(), L"Test 5");
		}
		TEST_METHOD(N_7_MUL_Nk_N_Tests) {
			Assert::AreEqual(N("0").ToString(), MUL_Nk_N(N("0"), 0).ToString(), L"Test 1");
			Assert::AreEqual(N("0").ToString(), MUL_Nk_N(N("0"), 5).ToString(), L"Test 2");
			Assert::AreEqual(N("1000").ToString(), MUL_Nk_N(N("1"), 3).ToString(), L"Test 3");
			Assert::AreEqual(N("100").ToString(), MUL_Nk_N(N("100"), 0).ToString(), L"Test 4");
			Assert::AreEqual(N("100000000000").ToString(), MUL_Nk_N(N("1"), 11).ToString(), L"Test 5");
			Assert::AreEqual(N("1000").ToString(), MUL_Nk_N(N("10"), 2).ToString(), L"Test 6");
		}
		TEST_METHOD(N_8_MUL_NN_N_Tests) {
			Assert::AreEqual(N("0").ToString(), MUL_NN_N(N("0"), N("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("0").ToString(), MUL_NN_N(N("0"), N("10")).ToString(), L"Test 2");
			Assert::AreEqual(N("0").ToString(), MUL_NN_N(N("100"), N("0")).ToString(), L"Test 3");
			Assert::AreEqual(N("100").ToString(), MUL_NN_N(N("10"), N("10")).ToString(), L"Test 4");
			Assert::AreEqual(N("12").ToString(), MUL_NN_N(N("1"), N("12")).ToString(), L"Test 5");
			Assert::AreEqual(N("999").ToString(), MUL_NN_N(N("999"), N("1")).ToString(), L"Test 6");
			Assert::AreEqual(N("8991").ToString(), MUL_NN_N(N("999"), N("9")).ToString(), L"Test 7");
		}
		TEST_METHOD(N_9_SUB_NDN_N_Tests) {
			Assert::AreEqual(N("0").ToString(), SUB_NDN_N(N("0"), 9, N("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("0").ToString(), SUB_NDN_N(N("0"), 0, N("10")).ToString(), L"Test 2");
			Assert::AreEqual(N("100").ToString(), SUB_NDN_N(N("100"), 5, N("0")).ToString(), L"Test 3");
			Assert::AreEqual(N("10").ToString(), SUB_NDN_N(N("100"), 9, N("10")).ToString(), L"Test 4");
			Assert::AreEqual(N("1").ToString(), SUB_NDN_N(N("1"), 0, N("12")).ToString(), L"Test 5");
			Assert::AreEqual(N("1").ToString(), SUB_NDN_N(N("1000"), 9, N("111")).ToString(), L"Test 6");
			Assert::AreEqual(N("990").ToString(), SUB_NDN_N(N("999"), 1, N("9")).ToString(), L"Test 7");
		}
		TEST_METHOD(N_10_DIV_NN_Dk_Tests) {
			int k = 0;
			Assert::AreEqual(9, DIV_NN_Dk(N("9"), N("1"), k), L"Test 1.1");
			Assert::AreEqual(0, k, L"Test 1.2");
			Assert::AreEqual(1, DIV_NN_Dk(N("10"), N("10"), k), L"Test 2.1");
			Assert::AreEqual(0, k, L"Test 2.2");
			Assert::AreEqual(3, DIV_NN_Dk(N("100"), N("3"), k), L"Test 3.1");
			Assert::AreEqual(1, k, L"Test 3.2");
			Assert::AreEqual(1, DIV_NN_Dk(N("100"), N("10"), k), L"Test 4.1");
			Assert::AreEqual(1, k, L"Test 4.2");
			Assert::AreEqual(4, DIV_NN_Dk(N("12"), N("3"), k), L"Test 5.1");
			Assert::AreEqual(0, k, L"Test 5.2");
			Assert::AreEqual(7, DIV_NN_Dk(N("631"), N("9"), k), L"Test 6.1");
			Assert::AreEqual(1, k, L"Test 6.2");
			Assert::AreEqual(5, DIV_NN_Dk(N("30"), N("6"), k), L"Test 7.1");
			Assert::AreEqual(0, k, L"Test 7.2");
		}
		TEST_METHOD(N_11_DIV_NN_N_Tests) {
			Assert::AreEqual(N("2").ToString(), DIV_NN_N(N("1"), N("2")).ToString(), L"Test 1");
			Assert::AreEqual(N("1").ToString(), DIV_NN_N(N("3"), N("2")).ToString(), L"Test 2");
			Assert::AreEqual(N("5").ToString(), DIV_NN_N(N("25"), N("5")).ToString(), L"Test 3");
			Assert::AreEqual(N("100").ToString(), DIV_NN_N(N("1000"), N("10")).ToString(), L"Test 4");
			Assert::AreEqual(N("36").ToString(), DIV_NN_N(N("396"), N("11")).ToString(), L"Test 5");
			Assert::AreEqual(N("1").ToString(), DIV_NN_N(N("55"), N("55")).ToString(), L"Test 6");
		}
		TEST_METHOD(N_12_MOD_NN_N_Tests) {
			Assert::AreEqual(N("0").ToString(), MOD_NN_N(N("1"), N("2")).ToString(), L"Test 1");
			Assert::AreEqual(N("1").ToString(), MOD_NN_N(N("3"), N("2")).ToString(), L"Test 2");
			Assert::AreEqual(N("4").ToString(), MOD_NN_N(N("25"), N("7")).ToString(), L"Test 3");
			Assert::AreEqual(N("0").ToString(), MOD_NN_N(N("1000"), N("10")).ToString(), L"Test 4");
			Assert::AreEqual(N("96").ToString(), MOD_NN_N(N("396"), N("100")).ToString(), L"Test 5");
			Assert::AreEqual(N("0").ToString(), MOD_NN_N(N("55"), N("55")).ToString(), L"Test 6");
		}
		TEST_METHOD(N_13_GCF_NN_N_Tests) {
			Assert::AreEqual(N("0").ToString(), GCF_NN_N(N("0"), N("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("1").ToString(), GCF_NN_N(N("3"), N("2")).ToString(), L"Test 2");
			Assert::AreEqual(N("5").ToString(), GCF_NN_N(N("25"), N("5")).ToString(), L"Test 3");
			Assert::AreEqual(N("5").ToString(), GCF_NN_N(N("25"), N("15")).ToString(), L"Test 4");
			Assert::AreEqual(N("6").ToString(), GCF_NN_N(N("0"), N("6")).ToString(), L"Test 5");
			Assert::AreEqual(N("11").ToString(), GCF_NN_N(N("55"), N("11")).ToString(), L"Test 6");
		}
		TEST_METHOD(N_14_LCM_NN_N_Tests) {
			Assert::AreEqual(N("3").ToString(), LCM_NN_N(N("1"), N("3")).ToString(), L"Test 1");
			Assert::AreEqual(N("6").ToString(), LCM_NN_N(N("3"), N("2")).ToString(), L"Test 2");
			Assert::AreEqual(N("25").ToString(), LCM_NN_N(N("25"), N("5")).ToString(), L"Test 3");
			Assert::AreEqual(N("4").ToString(), LCM_NN_N(N("4"), N("4")).ToString(), L"Test 4");
			Assert::AreEqual(N("35").ToString(), LCM_NN_N(N("5"), N("7")).ToString(), L"Test 5");
			Assert::AreEqual(N("12").ToString(), LCM_NN_N(N("4"), N("6")).ToString(), L"Test 6");
		}
	};
	TEST_CLASS(ZTests) {
	public:
		TEST_METHOD(Z_1_ABS_Z_N_Tests) {
			Assert::AreEqual(N("0").ToString(), ABS_Z_N(Z("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("9").ToString(), ABS_Z_N(Z("-9")).ToString(), L"Test 2");
			Assert::AreEqual(N("100").ToString(), ABS_Z_N(Z("100")).ToString(), L"Test 3");
		}
		TEST_METHOD(Z_2_POZ_Z_D_Tests) {
			Assert::AreEqual(0, POZ_Z_D(Z("0")), L"Test 1");
			Assert::AreEqual(1, POZ_Z_D(Z("-5")), L"Test 2");
			Assert::AreEqual(2, POZ_Z_D(Z("10")), L"Test 3");
		}
		TEST_METHOD(Z_3_MUL_ZM_Z_Tests) {
			Assert::AreEqual(Z("0").ToString(), MUL_ZM_Z(Z("0")).ToString(), L"Test 1");
			Assert::AreEqual(Z("9").ToString(), MUL_ZM_Z(Z("-9")).ToString(), L"Test 2");
			Assert::AreEqual(Z("-100").ToString(), MUL_ZM_Z(Z("100")).ToString(), L"Test 3");
		}
		TEST_METHOD(Z_4_TRANS_N_Z_Tests) {
			Assert::AreEqual(Z("0").ToString(), TRANS_N_Z(N("0")).ToString(), L"Test 1");
			Assert::AreEqual(Z("9").ToString(), TRANS_N_Z(N("9")).ToString(), L"Test 2");
			Assert::AreEqual(Z("100").ToString(), TRANS_N_Z(N("100")).ToString(), L"Test 3");
		}
		TEST_METHOD(Z_5_TRANS_Z_N_Tests) {
			Assert::AreEqual(N("0").ToString(), TRANS_Z_N(Z("0")).ToString(), L"Test 1");
			Assert::AreEqual(N("9").ToString(), TRANS_Z_N(Z("-9")).ToString(), L"Test 2");
			Assert::AreEqual(N("100").ToString(), TRANS_Z_N(Z("100")).ToString(), L"Test 3");
		}
		TEST_METHOD(Z_6_ADD_ZZ_Z_Tests) {
			Assert::AreEqual(Z("0").ToString(), ADD_ZZ_Z(Z("0"), Z("0")).ToString(), L"Test 1");
			Assert::AreEqual(Z("10").ToString(), ADD_ZZ_Z(Z("0"), Z("10")).ToString(), L"Test 2");
			Assert::AreEqual(Z("-100").ToString(), ADD_ZZ_Z(Z("-100"), Z("0")).ToString(), L"Test 3");
			Assert::AreEqual(Z("20").ToString(), ADD_ZZ_Z(Z("10"), Z("10")).ToString(), L"Test 4");
			Assert::AreEqual(Z("-100").ToString(), ADD_ZZ_Z(Z("-1"), Z("-99")).ToString(), L"Test 5");
			Assert::AreEqual(Z("0").ToString(), ADD_ZZ_Z(Z("999"), Z("-999")).ToString(), L"Test 6");
			Assert::AreEqual(Z("1010").ToString(), ADD_ZZ_Z(Z("999"), Z("11")).ToString(), L"Test 7");
		}
		TEST_METHOD(Z_7_SUB_ZZ_Z_Tests) {
			Assert::AreEqual(Z("0").ToString(), SUB_ZZ_Z(Z("0"), Z("0")).ToString(), L"Test 1");
			Assert::AreEqual(Z("-10").ToString(), SUB_ZZ_Z(Z("0"), Z("10")).ToString(), L"Test 2");
			Assert::AreEqual(Z("-100").ToString(), SUB_ZZ_Z(Z("-100"), Z("0")).ToString(), L"Test 3");
			Assert::AreEqual(Z("0").ToString(), SUB_ZZ_Z(Z("10"), Z("10")).ToString(), L"Test 4");
			Assert::AreEqual(Z("98").ToString(), SUB_ZZ_Z(Z("-1"), Z("-99")).ToString(), L"Test 5");
			Assert::AreEqual(Z("1000").ToString(), SUB_ZZ_Z(Z("999"), Z("-1")).ToString(), L"Test 6");
			Assert::AreEqual(Z("0").ToString(), SUB_ZZ_Z(Z("-11"), Z("-11")).ToString(), L"Test 7");
		}
		TEST_METHOD(Z_8_MUL_ZZ_Z_Tests) {
			Assert::AreEqual(Z("0").ToString(), MUL_ZZ_Z(Z("0"), Z("0")).ToString(), L"Test 1");
			Assert::AreEqual(Z("0").ToString(), MUL_ZZ_Z(Z("0"), Z("10")).ToString(), L"Test 2");
			Assert::AreEqual(Z("0").ToString(), MUL_ZZ_Z(Z("-100"), Z("0")).ToString(), L"Test 3");
			Assert::AreEqual(Z("-100").ToString(), MUL_ZZ_Z(Z("10"), Z("-10")).ToString(), L"Test 4");
			Assert::AreEqual(Z("99").ToString(), MUL_ZZ_Z(Z("-1"), Z("-99")).ToString(), L"Test 5");
			Assert::AreEqual(Z("-999").ToString(), MUL_ZZ_Z(Z("999"), Z("-1")).ToString(), L"Test 6");
			Assert::AreEqual(Z("121").ToString(), MUL_ZZ_Z(Z("11"), Z("11")).ToString(), L"Test 7");
		}
		TEST_METHOD(Z_9_DIV_ZN_Z_Tests) {
			Assert::AreEqual(Z("-2").ToString(), DIV_ZN_Z(Z("-2"), N("1")).ToString(), L"Test 1");
			Assert::AreEqual(Z("2").ToString(), DIV_ZN_Z(Z("4"), N("2")).ToString(), L"Test 2");
			Assert::AreEqual(Z("3").ToString(), DIV_ZN_Z(Z("10"), N("3")).ToString(), L"Test 3");
			Assert::AreEqual(Z("-4").ToString(), DIV_ZN_Z(Z("-11"), N("3")).ToString(), L"Test 4");
			Assert::AreEqual(Z("1").ToString(), DIV_ZN_Z(Z("100"), N("99")).ToString(), L"Test 5");
			Assert::AreEqual(Z("5").ToString(), DIV_ZN_Z(Z("25"), N("5")).ToString(), L"Test 6");
			Assert::AreEqual(Z("10").ToString(), DIV_ZN_Z(Z("100"), N("10")).ToString(), L"Test 7");
		}
		TEST_METHOD(Z_10_MOD_ZN_Z_Tests) {
			Assert::AreEqual(Z("0").ToString(), MOD_ZN_Z(Z("-2"), N("1")).ToString(), L"Test 1");
			Assert::AreEqual(Z("0").ToString(), MOD_ZN_Z(Z("4"), N("2")).ToString(), L"Test 2");
			Assert::AreEqual(Z("1").ToString(), MOD_ZN_Z(Z("10"), N("3")).ToString(), L"Test 3");
			Assert::AreEqual(Z("1").ToString(), MOD_ZN_Z(Z("-11"), N("3")).ToString(), L"Test 4");
			Assert::AreEqual(Z("1").ToString(), MOD_ZN_Z(Z("100"), N("99")).ToString(), L"Test 5");
			Assert::AreEqual(Z("0").ToString(), MOD_ZN_Z(Z("25"), N("5")).ToString(), L"Test 6");
			Assert::AreEqual(Z("5").ToString(), MOD_ZN_Z(Z("17"), N("6")).ToString(), L"Test 7");
		}
	};
	TEST_CLASS(QTests) {
	public:
		TEST_METHOD(Q_1_RED_Q_Q_Tests) {
			Assert::AreEqual(Q("0").ToString(), RED_Q_Q(Q("0")).ToString(), L"Test 1");
			Assert::AreEqual(Q("-3").ToString(), RED_Q_Q(Q("-9/3")).ToString(), L"Test 2");
			Assert::AreEqual(Q("17/13").ToString(), RED_Q_Q(Q("17/13")).ToString(), L"Test 3");
		}
		TEST_METHOD(Q_2_INT_Q_B_Tests) {
			Assert::AreEqual(true, INT_Q_B(Q("0")), L"Test 1");
			Assert::AreEqual(false, INT_Q_B(Q("-5/7")), L"Test 2");
			Assert::AreEqual(true, INT_Q_B(Q("27/9")), L"Test 3");
		}
		TEST_METHOD(Q_3_TRANS_Z_Q_Tests) {
			Assert::AreEqual(Q("0").ToString(), TRANS_Z_Q(Z("0")).ToString(), L"Test 1");
			Assert::AreEqual(Q("-9").ToString(), TRANS_Z_Q(Z("-9")).ToString(), L"Test 2");
			Assert::AreEqual(Z("100").ToString(), TRANS_Z_Q(Z("100")).ToString(), L"Test 3");
		}
		TEST_METHOD(Q_4_TRANS_Q_Z_Tests) {
			Assert::AreEqual(Z("0").ToString(), TRANS_Q_Z(Q("0")).ToString(), L"Test 1");
			Assert::AreEqual(Z("-3").ToString(), TRANS_Q_Z(Q("-9/3")).ToString(), L"Test 2");
			Assert::AreEqual(Z("27").ToString(), TRANS_Q_Z(Q("27")).ToString(), L"Test 3");
		}
		TEST_METHOD(Q_5_ADD_QQ_Q_Tests) {
			Assert::AreEqual(Q("0").ToString(), ADD_QQ_Q(Q("0"), Q("0")).ToString(), L"Test 1");
			Assert::AreEqual(Q("-10/7").ToString(), ADD_QQ_Q(Q("0"), Q("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(Q("0").ToString(), ADD_QQ_Q(Q("-100/7"), Q("100/7")).ToString(), L"Test 3");
			Assert::AreEqual(Q("20/3").ToString(), ADD_QQ_Q(Q("10/3"), Q("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(Q("-100").ToString(), ADD_QQ_Q(Q("-1"), Q("-99")).ToString(), L"Test 5");
			Assert::AreEqual(Q("999/10").ToString(), ADD_QQ_Q(Q("999/5"), Q("-999/10")).ToString(), L"Test 6");
			Assert::AreEqual(Q("8/15").ToString(), ADD_QQ_Q(Q("1/3"), Q("1/5")).ToString(), L"Test 7");
		}
		TEST_METHOD(Q_6_SUB_QQ_Q_Tests) {
			Assert::AreEqual(Q("0").ToString(), SUB_QQ_Q(Q("0"), Q("0")).ToString(), L"Test 1");
			Assert::AreEqual(Q("10/7").ToString(), SUB_QQ_Q(Q("0"), Q("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(Q("-200/7").ToString(), SUB_QQ_Q(Q("-100/7"), Q("100/7")).ToString(), L"Test 3");
			Assert::AreEqual(Q("0").ToString(), SUB_QQ_Q(Q("10/3"), Q("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(Q("98").ToString(), SUB_QQ_Q(Q("-1"), Q("-99")).ToString(), L"Test 5");
			Assert::AreEqual(Q("-999/10").ToString(), SUB_QQ_Q(Q("-999/5"), Q("-999/10")).ToString(), L"Test 6");
			Assert::AreEqual(Q("2/15").ToString(), SUB_QQ_Q(Q("1/3"), Q("1/5")).ToString(), L"Test 7");
		}
		TEST_METHOD(Q_7_MUL_QQ_Q_Tests) {
			Assert::AreEqual(Q("0").ToString(), MUL_QQ_Q(Q("0"), Q("0")).ToString(), L"Test 1");
			Assert::AreEqual(Q("0").ToString(), MUL_QQ_Q(Q("0"), Q("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(Q("-1").ToString(), MUL_QQ_Q(Q("-100/7"), Q("7/100")).ToString(), L"Test 3");
			Assert::AreEqual(Q("100/9").ToString(), MUL_QQ_Q(Q("10/3"), Q("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(Q("99").ToString(), MUL_QQ_Q(Q("-1"), Q("-99")).ToString(), L"Test 5");
			Assert::AreEqual(Q("555").ToString(), MUL_QQ_Q(Q("-999/5"), Q("-25/9")).ToString(), L"Test 6");
			Assert::AreEqual(Q("1/15").ToString(), MUL_QQ_Q(Q("1/3"), Q("1/5")).ToString(), L"Test 7");
		}
		TEST_METHOD(Q_8_DIV_QQ_Q_Tests) {
			Assert::AreEqual(Q("0").ToString(), DIV_QQ_Q(Q("0"), Q("1/7")).ToString(), L"Test 1");
			Assert::AreEqual(Q("0").ToString(), DIV_QQ_Q(Q("0"), Q("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(Q("-1").ToString(), DIV_QQ_Q(Q("-100/7"), Q("100/7")).ToString(), L"Test 3");
			Assert::AreEqual(Q("1").ToString(), DIV_QQ_Q(Q("10/3"), Q("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(Q("1/99").ToString(), DIV_QQ_Q(Q("-1"), Q("-99")).ToString(), L"Test 5");
			Assert::AreEqual(Q("555").ToString(), DIV_QQ_Q(Q("-999/5"), Q("-9/25")).ToString(), L"Test 6");
			Assert::AreEqual(Q("5/3").ToString(), DIV_QQ_Q(Q("1/3"), Q("1/5")).ToString(), L"Test 7");
		}
	};
	TEST_CLASS(PTests) {
	public:
		TEST_METHOD(P_1_ADD_PP_P_Tests) {
			Assert::AreEqual(P("0").ToString(), ADD_PP_P(P("0"), P("0")).ToString(), L"Test 1");
			Assert::AreEqual(P("-10/7").ToString(), ADD_PP_P(P("0"), P("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(P("0").ToString(), ADD_PP_P(P("-100/7"), P("100/7")).ToString(), L"Test 3");
			Assert::AreEqual(P("20/3").ToString(), ADD_PP_P(P("10/3"), P("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(P("-100").ToString(), ADD_PP_P(P("-1"), P("-99")).ToString(), L"Test 5");
			Assert::AreEqual(P("999/10").ToString(), ADD_PP_P(P("999/5"), P("-999/10")).ToString(), L"Test 6");
			Assert::AreEqual(P("8/15").ToString(), ADD_PP_P(P("1/3"), P("1/5")).ToString(), L"Test 7");
			Assert::AreEqual(P("2x^6 + x^5").ToString(), ADD_PP_P(P("x^5"), P("2x^6")).ToString(), L"Test 8");
			Assert::AreEqual(P("5").ToString(), ADD_PP_P(P("-3x^5 + 5"), P("3x^5")).ToString(), L"Test 9");
			Assert::AreEqual(P("0").ToString(), ADD_PP_P(P("-3x^5 + 5"), P("3x^5 - 5")).ToString(), L"Test 10");
		}
		TEST_METHOD(P_2_SUB_PP_P_Tests) {
			Assert::AreEqual(P("0").ToString(), SUB_PP_P(P("0"), P("0")).ToString(), L"Test 1");
			Assert::AreEqual(P("10/7").ToString(), SUB_PP_P(P("0"), P("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(P("-200/7").ToString(), SUB_PP_P(P("-100/7"), P("100/7")).ToString(), L"Test 3");
			Assert::AreEqual(P("0").ToString(), SUB_PP_P(P("10/3"), P("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(P("98").ToString(), SUB_PP_P(P("-1"), P("-99")).ToString(), L"Test 5");
			Assert::AreEqual(P("-999/10").ToString(), SUB_PP_P(P("-999/5"), P("-999/10")).ToString(), L"Test 6");
			Assert::AreEqual(P("2/15").ToString(), SUB_PP_P(P("1/3"), P("1/5")).ToString(), L"Test 7");
			Assert::AreEqual(P("-2x^6 + x^5").ToString(), SUB_PP_P(P("x^5"), P("2x^6")).ToString(), L"Test 8");
			Assert::AreEqual(P("5").ToString(), SUB_PP_P(P("3x^5 + 5"), P("3x^5")).ToString(), L"Test 9");
			Assert::AreEqual(P("0").ToString(), SUB_PP_P(P("-3x^5 + 5"), P("-3x^5 + 5")).ToString(), L"Test 10");
			Assert::AreEqual(P("3x^5").ToString(), SUB_PP_P(P("3x^5"), P("0")).ToString(), L"Test 11");
		}
		TEST_METHOD(P_3_MUL_PQ_P_Tests) {
			Assert::AreEqual(P("0").ToString(), MUL_PQ_P(P("3x^10+6x+8"), Q("0")).ToString(), L"Test 1");
			Assert::AreEqual(P("-5x^2-10x").ToString(), MUL_PQ_P(P("2x^2+4x"), Q("-5/2")).ToString(), L"Test 2");
			Assert::AreEqual(P("0").ToString(), MUL_PQ_P(P("0"), Q("10")).ToString(), L"Test 3");
		}
		TEST_METHOD(P_4_MUL_Pxk_P_Tests) {
			Assert::AreEqual(P("3x^10+6x+8").ToString(), MUL_Pxk_P(P("3x^10+6x+8"), 0).ToString(), L"Test 1");
			Assert::AreEqual(P("2x^4+4x^3").ToString(), MUL_Pxk_P(P("2x^2+4x"), 2).ToString(), L"Test 2");
			Assert::AreEqual(P("0").ToString(), MUL_Pxk_P(P("0"), 10).ToString(), L"Test 3");
		}
		TEST_METHOD(P_5_LED_P_Q_Tests) {
			Assert::AreEqual(Q("3/4").ToString(), LED_P_Q(P("3/4x^10+6x+8")).ToString(), L"Test 1");
			Assert::AreEqual(Q("2").ToString(), LED_P_Q(P("2x^2+4x")).ToString(), L"Test 2");
			Assert::AreEqual(Q("0").ToString(), LED_P_Q(P("0")).ToString(), L"Test 3");
		}
		TEST_METHOD(P_6_DEG_P_N_Tests) {
			Assert::AreEqual(N("10").ToString(), DEG_P_N(P("3x^10+6x+8")).ToString(), L"Test 1");
			Assert::AreEqual(N("2").ToString(), DEG_P_N(P("2x^2+4x")).ToString(), L"Test 2");
			Assert::AreEqual(N("0").ToString(), DEG_P_N(P("0")).ToString(), L"Test 3");
		}
		TEST_METHOD(P_7_FAC_P_Q_Tests) {
			Assert::AreEqual(Q("3/4").ToString(), FAC_P_Q(P("3/4x^10+6/2x+9")).ToString(), L"Test 1");
			Assert::AreEqual(Q("2").ToString(), FAC_P_Q(P("2x^2+4x")).ToString(), L"Test 2");
			Assert::AreEqual(Q("0").ToString(), FAC_P_Q(P("0")).ToString(), L"Test 3");
		}
		TEST_METHOD(P_8_MUL_PP_P_Tests) {
			Assert::AreEqual(P("0").ToString(), MUL_PP_P(P("0"), P("0")).ToString(), L"Test 1");
			Assert::AreEqual(P("0").ToString(), MUL_PP_P(P("0"), P("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(P("-1").ToString(), MUL_PP_P(P("-100/7"), P("7/100")).ToString(), L"Test 3");
			Assert::AreEqual(P("100/9").ToString(), MUL_PP_P(P("10/3"), P("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(P("99").ToString(), MUL_PP_P(P("-1"), P("-99")).ToString(), L"Test 5");
			Assert::AreEqual(P("555").ToString(), MUL_PP_P(P("-999/5"), P("-25/9")).ToString(), L"Test 6");
			Assert::AreEqual(P("1/15").ToString(), MUL_PP_P(P("1/3"), P("1/5")).ToString(), L"Test 7");
			Assert::AreEqual(P("12x^3+16/5x^2-7/2x").ToString(), MUL_PP_P(P("3x^2+4/5x-7/8"), P("4x")).ToString(), L"Test 8");
			Assert::AreEqual(P("0").ToString(), MUL_PP_P(P("12x^3+16/5x^2-7/2x"), P("0")).ToString(), L"Test 9");
			Assert::AreEqual(P("x^5").ToString(), MUL_PP_P(P("x^3"), P("x^2")).ToString(), L"Test 10");
		}
		TEST_METHOD(P_9_DIV_PP_P_Tests) {
			Assert::AreEqual(P("0").ToString(), DIV_PP_P(P("0"), P("1/7")).ToString(), L"Test 1");
			Assert::AreEqual(P("0").ToString(), DIV_PP_P(P("0"), P("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(P("-1").ToString(), DIV_PP_P(P("-100/7"), P("100/7")).ToString(), L"Test 3");
			Assert::AreEqual(P("1").ToString(), DIV_PP_P(P("10/3"), P("10/3")).ToString(), L"Test 4");
			Assert::AreEqual(P("1/99").ToString(), DIV_PP_P(P("-1"), P("-99")).ToString(), L"Test 5");
			Assert::AreEqual(P("555").ToString(), DIV_PP_P(P("-999/5"), P("-9/25")).ToString(), L"Test 6");
			Assert::AreEqual(P("x").ToString(), DIV_PP_P(P("x^2"), P("x")).ToString(), L"Test 7");
			Assert::AreEqual(P("x+4").ToString(), DIV_PP_P(P("x^2+5x+4"), P("x+1")).ToString(), L"Test 8");
			Assert::AreEqual(P("x^5").ToString(), DIV_PP_P(P("5x^5"), P("5")).ToString(), L"Test 9");
			Assert::AreEqual(P("x^3").ToString(), DIV_PP_P(P("x^5"), P("x^2")).ToString(), L"Test 10");
		}
		TEST_METHOD(P_10_MOD_PP_P_Tests) {
			Assert::AreEqual(P("0").ToString(), MOD_PP_P(P("0"), P("1/7")).ToString(), L"Test 1");
			Assert::AreEqual(P("0").ToString(), MOD_PP_P(P("0"), P("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(P("-100/7").ToString(), MOD_PP_P(P("-100/7"), P("100/7x")).ToString(), L"Test 3");
			Assert::AreEqual(P("10/3x").ToString(), MOD_PP_P(P("10/3x"), P("10/3x^3")).ToString(), L"Test 4");
			Assert::AreEqual(P("0").ToString(), MOD_PP_P(P("-1"), P("-99")).ToString(), L"Test 5");
			Assert::AreEqual(P("-x").ToString(), MOD_PP_P(P("-5x^3-x"), P("x^2")).ToString(), L"Test 6");
			Assert::AreEqual(P("0").ToString(), MOD_PP_P(P("x^2"), P("x")).ToString(), L"Test 7");
			Assert::AreEqual(P("0").ToString(), MOD_PP_P(P("x^2+5x+4"), P("x+1")).ToString(), L"Test 8");
			Assert::AreEqual(P("3").ToString(), MOD_PP_P(P("5x^5+3"), P("5x^5")).ToString(), L"Test 9");
			Assert::AreEqual(P("x+5").ToString(), MOD_PP_P(P("x^5+x^2+x+5"), P("x^2")).ToString(), L"Test 10");
		}
		TEST_METHOD(P_11_GCF_PP_P_Tests) {
			Assert::AreEqual(P("1/7").ToString(), GCF_PP_P(P("0"), P("1/7")).ToString(), L"Test 1");
			Assert::AreEqual(P("10/7").ToString(), GCF_PP_P(P("0"), P("-10/7")).ToString(), L"Test 2");
			Assert::AreEqual(P("100/7").ToString(), GCF_PP_P(P("-100/7"), P("100/7x")).ToString(), L"Test 3");
			Assert::AreEqual(P("10/3x").ToString(), GCF_PP_P(P("10/3x"), P("10/3x^3")).ToString(), L"Test 4");
			Assert::AreEqual(P("1").ToString(), GCF_PP_P(P("-1"), P("-99")).ToString(), L"Test 5");
			Assert::AreEqual(P("x").ToString(), GCF_PP_P(P("-5x^3-x"), P("x^2")).ToString(), L"Test 6");
			Assert::AreEqual(P("x").ToString(), GCF_PP_P(P("x^2"), P("x")).ToString(), L"Test 7");
			Assert::AreEqual(P("x+1").ToString(), GCF_PP_P(P("x^2+5x+4"), P("x+1")).ToString(), L"Test 8");
			Assert::AreEqual(P("3").ToString(), GCF_PP_P(P("5x^5+3"), P("5x^5")).ToString(), L"Test 9");
			Assert::AreEqual(P("25").ToString(), GCF_PP_P(P("x^5+x^2+x+5"), P("x^2")).ToString(), L"Test 10");
		}
		TEST_METHOD(P_12_DER_P_P_Tests) {
			Assert::AreEqual(P("15/2x^9+6").ToString(), DER_P_P(P("3/4x^10+6x+8")).ToString(), L"Test 1");
			Assert::AreEqual(P("4x+4").ToString(), DER_P_P(P("2x^2+4x")).ToString(), L"Test 2");
			Assert::AreEqual(P("0").ToString(), DER_P_P(P("12")).ToString(), L"Test 3");
		}
		TEST_METHOD(P_13_NMR_P_P_Tests) {
			Assert::AreEqual(P("x+2").ToString(), NMR_P_P(P("x^2+4x+4")).ToString(), L"Test 1");
			Assert::AreEqual(P("5x+3").ToString(), NMR_P_P(P("5x+3")).ToString(), L"Test 2");
			Assert::AreEqual(P("0").ToString(), NMR_P_P(P("0")).ToString(), L"Test 3");
		}
	};
}
