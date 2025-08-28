#include <stdio.h>
#include "pico/stdlib.h"

#define BID_THREAD
#define DECIMAL_CALL_BY_REFERENCE 1
#define DECIMAL_GLOBAL_ROUNDING 1
#define DECIMAL_GLOBAL_EXCEPTION_FLAGS 1

// Intel DFP headers (installed via target_include_directories)
#include "bid_conf.h"
#include "bid_functions.h"

void calculator_example()
{
    BID_UINT128 a, b, c, result;
    char output[64];

    // 初期化
    _IDEC_glbflags = BID_EXACT_STATUS;
    _IDEC_glbround = BID_ROUNDING_TO_NEAREST;

    printf("\n=== Intel Decimal Floating-Point 算術関数テスト ===\n");

    // 基本的な算術演算のテスト
    printf("\n=== 基本算術演算テスト ===\n");
    __bid128_from_string(&a, "123.456");
    __bid128_from_string(&b, "78.9");
    __bid128_from_string(&c, "2.0");

    // 加算
    __bid128_add(&result, &a, &b);
    __bid128_to_string(output, &result);
    printf("123.456 + 78.9 = %s\n", output);

    // 減算
    __bid128_sub(&result, &a, &b);
    __bid128_to_string(output, &result);
    printf("123.456 - 78.9 = %s\n", output);

    // 乗算
    __bid128_mul(&result, &a, &b);
    __bid128_to_string(output, &result);
    printf("123.456 * 78.9 = %s\n", output);

    // 除算
    __bid128_div(&result, &a, &b);
    __bid128_to_string(output, &result);
    printf("123.456 / 78.9 = %s\n", output);

    // 複合計算: result = (a + b) / c
    BID_UINT128 temp;
    __bid128_add(&temp, &a, &b);
    __bid128_div(&result, &temp, &c);
    __bid128_to_string(output, &result);
    printf("(123.456 + 78.9) / 2.0 = %s\n", output);

    // 例外フラグのチェック
    if (_IDEC_glbflags != BID_EXACT_STATUS)
    {
        printf("Warning: Computation was not exact\n");
    }

    // 三角関数のテスト
    printf("\n=== 三角関数テスト ===\n");
    __bid128_from_string(&a, "0.5"); // a = 0.5
    __bid128_sin(&result, &a);
    __bid128_to_string(output, &result);
    printf("sin(0.5) = %s\n", output);

    __bid128_cos(&result, &a);
    __bid128_to_string(output, &result);
    printf("cos(0.5) = %s\n", output);

    __bid128_tan(&result, &a);
    __bid128_to_string(output, &result);
    printf("tan(0.5) = %s\n", output);

    // 指数・対数関数のテスト
    printf("\n=== 指数・対数関数テスト ===\n");
    __bid128_from_string(&a, "2.0");
    __bid128_exp(&result, &a);
    __bid128_to_string(output, &result);
    printf("exp(2.0) = %s\n", output);

    __bid128_from_string(&a, "10.0");
    __bid128_log(&result, &a);
    __bid128_to_string(output, &result);
    printf("log(10.0) = %s\n", output);

    __bid128_log10(&result, &a);
    __bid128_to_string(output, &result);
    printf("log10(10.0) = %s\n", output);

    // 平方根・累乗関数のテスト
    printf("\n=== 平方根・累乗関数テスト ===\n");
    __bid128_from_string(&a, "16.0");
    __bid128_sqrt(&result, &a);
    __bid128_to_string(output, &result);
    printf("sqrt(16.0) = %s\n", output);

    __bid128_from_string(&a, "2.0");
    __bid128_from_string(&b, "3.0");
    __bid128_pow(&result, &a, &b);
    __bid128_to_string(output, &result);
    printf("pow(2.0, 3.0) = %s\n", output);

    // 双曲線関数のテスト
    printf("\n=== 双曲線関数テスト ===\n");
    __bid128_from_string(&a, "1.0");
    __bid128_sinh(&result, &a);
    __bid128_to_string(output, &result);
    printf("sinh(1.0) = %s\n", output);

    __bid128_cosh(&result, &a);
    __bid128_to_string(output, &result);
    printf("cosh(1.0) = %s\n", output);

    __bid128_tanh(&result, &a);
    __bid128_to_string(output, &result);
    printf("tanh(1.0) = %s\n", output);

    // 逆三角関数のテスト
    printf("\n=== 逆三角関数テスト ===\n");
    __bid128_from_string(&a, "0.5");
    __bid128_asin(&result, &a);
    __bid128_to_string(output, &result);
    printf("asin(0.5) = %s\n", output);

    __bid128_acos(&result, &a);
    __bid128_to_string(output, &result);
    printf("acos(0.5) = %s\n", output);

    __bid128_from_string(&a, "1.0");
    __bid128_atan(&result, &a);
    __bid128_to_string(output, &result);
    printf("atan(1.0) = %s\n", output);

    // その他の数学関数のテスト
    printf("\n=== その他の数学関数テスト ===\n");
    __bid128_from_string(&a, "-3.7");
    __bid128_round_integral_exact(&result, &a);
    __bid128_to_string(output, &result);
    printf("round(-3.7) = %s\n", output);

    __bid128_abs(&result, &a);
    __bid128_to_string(output, &result);
    printf("abs(-3.7) = %s\n", output);

    __bid128_from_string(&a, "3.2");
    __bid128_from_string(&b, "2.1");
    __bid128_fmod(&result, &a, &b);
    __bid128_to_string(output, &result);
    printf("fmod(3.2, 2.1) = %s\n", output);

    __bid128_from_string(&a, "2.5");
    __bid128_from_string(&b, "3.1");
    __bid128_quantize(&result, &a, &b);
    __bid128_to_string(output, &result);
    printf("quantize(2.5, 3.1) = %s\n", output);

    // 比較関数のテスト
    printf("\n=== 比較関数テスト ===\n");
    __bid128_from_string(&a, "2.5");
    __bid128_from_string(&b, "3.1");
    
    int cmp_result;
    
    __bid128_quiet_greater(&cmp_result, &a, &b);
    if (cmp_result)
        printf("2.5 > 3.1: true\n");
    else
        printf("2.5 > 3.1: false\n");
    
    __bid128_quiet_less(&cmp_result, &a, &b);
    if (cmp_result)
        printf("2.5 < 3.1: true\n");
    else
        printf("2.5 < 3.1: false\n");
    
    __bid128_quiet_equal(&cmp_result, &a, &b);
    if (cmp_result)
        printf("2.5 == 3.1: true\n");
    else
        printf("2.5 == 3.1: false\n");
}

int main()
{
    stdio_init_all();

    while (true)
    {
        calculator_example();
        printf("\n\n\n\n\n");
        sleep_ms(1000);
    }
}