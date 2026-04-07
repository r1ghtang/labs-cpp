#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 5;

// Функция вывода матрицы
void printMatrix(float m[N][N]) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(8) << fixed << setprecision(2) << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Минимум всей матрицы
float minMatrix(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < mn) mn = m[i][j];
        }
    }
    return mn;
}

// Максимум всей матрицы
float maxMatrix(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > mx) mx = m[i][j];
        }
    }
    return mx;
}

// Максимум нижнетреугольной части (i >= j)
float maxLower(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] > mx) mx = m[i][j];
        }
    }
    return mx;
}

// Максимум верхнетреугольной части (i <= j)
float maxUpper(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > mx) mx = m[i][j];
        }
    }
    return mx;
}

// Минимум нижнетреугольной части
float minLower(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] < mn) mn = m[i][j];
        }
    }
    return mn;
}

// Минимум верхнетреугольной части
float minUpper(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < mn) mn = m[i][j];
        }
    }
    return mn;
}

// Минимум главной диагонали
float minMainDiag(float m[N][N]) {
    float mn = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] < mn) mn = m[i][i];
    }
    return mn;
}

// Максимум главной диагонали
float maxMainDiag(float m[N][N]) {
    float mx = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] > mx) mx = m[i][i];
    }
    return mx;
}

// Минимум побочной диагонали
float minSideDiag(float m[N][N]) {
    float mn = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] < mn) mn = m[i][N - 1 - i];
    }
    return mn;
}

// Максимум побочной диагонали
float maxSideDiag(float m[N][N]) {
    float mx = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] > mx) mx = m[i][N - 1 - i];
    }
    return mx;
}

// Среднее арифметическое всех элементов
float avgMatrix(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// Среднее арифметическое нижнетреугольной части
float avgLower(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Среднее арифметическое верхнетреугольной части
float avgUpper(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum / count;
}

// Суммы строк
void rowSums(float m[N][N]) {
    cout << "Row sums:" << endl;
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        cout << "Row " << i << ": " << sum << endl;
    }
    cout << endl;
}

// Суммы столбцов
void colSums(float m[N][N]) {
    cout << "Column sums:" << endl;
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        cout << "Column " << j << ": " << sum << endl;
    }
    cout << endl;
}

// Минимальные значения строк
void rowMins(float m[N][N]) {
    cout << "Row minimums:" << endl;
    for (int i = 0; i < N; i++) {
        float mn = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] < mn) mn = m[i][j];
        }
        cout << "Row " << i << ": " << mn << endl;
    }
    cout << endl;
}
// Минимальные значения столбцов
void colMins(float m[N][N]) {
    cout << "Column minimums:" << endl;
    for (int j = 0; j < N; j++) {
        float mn = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] < mn) mn = m[i][j];
        }
        cout << "Column " << j << ": " << mn << endl;
    }
    cout << endl;
}

// Максимальные значения строк
void rowMaxs(float m[N][N]) {
    cout << "Row maximums:" << endl;
    for (int i = 0; i < N; i++) {
        float mx = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] > mx) mx = m[i][j];
        }
        cout << "Row " << i << ": " << mx << endl;
    }
    cout << endl;
}

// Максимальные значения столбцов
void colMaxs(float m[N][N]) {
    cout << "Column maximums:" << endl;
    for (int j = 0; j < N; j++) {
        float mx = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] > mx) mx = m[i][j];
        }
        cout << "Column " << j << ": " << mx << endl;
    }
    cout << endl;
}

// Средние значения строк
void rowAvgs(float m[N][N]) {
    cout << "Row averages:" << endl;
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
        cout << "Row " << i << ": " << sum / N << endl;
    }
    cout << endl;
}

// Средние значения столбцов
void colAvgs(float m[N][N]) {
    cout << "Column averages:" << endl;
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        cout << "Column " << j << ": " << sum / N << endl;
    }
    cout << endl;
}

// Сумма нижнетреугольной части
float sumLower(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}

// Сумма верхнетреугольной части
float sumUpper(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum;
}

// Элемент, наиболее близкий к среднему арифметическому
float nearestToAverage(float m[N][N]) {
    float avg = avgMatrix(m);
    float best = m[0][0];
    float diff = (m[0][0] > avg) ? (m[0][0] - avg) : (avg - m[0][0]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float currentDiff = (m[i][j] > avg) ? (m[i][j] - avg) : (avg - m[i][j]);
            if (currentDiff < diff) {
                diff = currentDiff;
                best = m[i][j];
            }
        }
    }
    return best;
}

// Сумма главной диагонали (чтобы не было двойного учёта)
float sumMainDiag(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += m[i][i];
    }
    return sum;
}

int main() {
    float m[N][N];

    // Заполняем матрицу случайными числами
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = rand() % 100 / 10.0;
        }
    }

    // Выводим матрицу
    printMatrix(m);

    // Вывод результатов всех заданий
    cout << "Min matrix = " << minMatrix(m) << endl;
    cout << "Max matrix = " << maxMatrix(m) << endl;

    cout << "Max lower triangle = " << maxLower(m) << endl;
    cout << "Max upper triangle = " << maxUpper(m) << endl;
    cout << "Min lower triangle = " << minLower(m) << endl;
    cout << "Min upper triangle = " << minUpper(m) << endl;

    cout << "Min main diagonal = " << minMainDiag(m) << endl;
    cout << "Max main diagonal = " << maxMainDiag(m) << endl;
    cout << "Min side diagonal = " << minSideDiag(m) << endl;
    cout << "Max side diagonal = " << maxSideDiag(m) << endl;

    cout << "Average of matrix = " << avgMatrix(m) << endl;
    cout << "Average of lower triangle = " << avgLower(m) << endl;
    cout << "Average of upper triangle = " << avgUpper(m) << endl;

    cout << "Sum of lower triangle = " << sumLower(m) << endl;
    cout << "Sum of upper triangle = " << sumUpper(m) << endl;
    
    // Сумма нижней и верхней частей без двойного учёта диагонали
    cout << "Sum of lower and upper triangles = " << sumLower(m) + sumUpper(m) - sumMainDiag(m) << endl;

    cout << "Nearest element to average = " << nearestToAverage(m) << endl << endl;

    rowSums(m);
    colSums(m);
    rowMins(m);
    colMins(m);
    rowMaxs(m);
    colMaxs(m);
    rowAvgs(m);
    colAvgs(m);

    return 0;
}
