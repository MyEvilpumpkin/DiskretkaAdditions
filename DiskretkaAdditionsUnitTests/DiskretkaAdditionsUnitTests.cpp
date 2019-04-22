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
}
