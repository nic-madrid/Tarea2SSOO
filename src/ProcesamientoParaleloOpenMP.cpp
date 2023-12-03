#include <opencv2/highgui.hpp>
#include <iostream>
#include <omp.h>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main() {
    // Pedir al usuario el nombre de la imagen de entrada
    cout << "Ingrese el nombre de la imagen de entrada (con extension, por ejemplo, imagen.jpg): ";
    string inputName;
    cin >> inputName;

    // Pedir al usuario el nombre de la imagen de salida
    cout << "Ingrese el nombre de la imagen de salida (con extension, por ejemplo, salida.png): ";
    string outputName;
    cin >> outputName;

    // Pedir al usuario la cantidad de hilos a utilizar
    int numThreads;
    cout << "Ingrese el numero de hilos a utilizar: ";
    cin >> numThreads;

    // Ruta de la imagen de entrada
    string inputPath = "imagenes/" + inputName;

    // Ruta de la imagen de salida
    string outputPath = "imagenesConvertidas/" + outputName;

    // Cargar la imagen desde el archivo de entrada
    Mat img = imread(inputPath);

    if (img.empty()) {
        cout << "No se pudo cargar la imagen de entrada: " << inputPath << endl;
        return 1;
    }

    // Obtener las dimensiones de la imagen
    int rows = img.rows;
    int cols = img.cols;

    // Asegurarse de que el número de hilos no sea mayor que el número de filas
    numThreads = min(numThreads, rows);

    // Convertir la imagen a escala de grises sin utilizar funciones de OpenCV
    Mat grayImg(rows, cols, CV_8UC1);  // Matriz para la imagen en escala de grises

    auto start = high_resolution_clock::now();

#pragma omp parallel for num_threads(numThreads)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Vec3b pixel = img.at<Vec3b>(i, j);

            // Calcular el valor de gris ponderado por la luminosidad
            uchar grayValue = static_cast<uchar>(0.21 * pixel[2] + 0.72 * pixel[1] + 0.07 * pixel[0]);

            // Asignar el nuevo valor al pixel en la imagen en escala de grises
            grayImg.at<uchar>(i, j) = grayValue;
        }
    }

    auto stop = high_resolution_clock::now();

    // Mostrar el tiempo de ejecución en milisegundos
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;

    // Mostrar la imagen original y la imagen en escala de grises
    imshow("Imagen Original", img);
    imshow("Imagen en Escala de Grises (Luminosidad)", grayImg);

    // Esperar hasta que se presione una tecla
    waitKey(0);

    // Guardar la imagen en escala de grises en el archivo de salida
    imwrite(outputPath, grayImg);

    cout << "Imagen en escala de grises (Luminosidad) guardada en: " << outputPath << endl;

    return 0;
}