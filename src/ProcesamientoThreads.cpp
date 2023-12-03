#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

// Funcion que convierte una parte de la imagen a escala de grises
void convertToGrayscale(const Mat& input, Mat& output, int startRow, int endRow) {
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < input.cols; j++) {
            Vec3b pixel = input.at<Vec3b>(i, j);
            uchar luminosity = static_cast<uchar>(0.3 * pixel[2] + 0.59 * pixel[1] + 0.11 * pixel[0]);
            output.at<uchar>(i, j) = luminosity;
        }
    }
}

int main() {
    // Carpeta que contiene las imagenes de entrada
    string folderName = "imagenes";

    // Pedir al usuario el nombre de la imagen de entrada
    cout << "Ingrese el nombre de la imagen de entrada (con extension, por ejemplo, imagen.jpg): ";
    string inputName;
    cin >> inputName;

    // Pedir al usuario el nombre de la imagen de salida
    cout << "Ingrese el nombre de la imagen de salida (con extension, por ejemplo, salida.png): ";
    string outputName;
    cin >> outputName;

    // Construir las rutas completas de los archivos de entrada y salida
    string inputPath = folderName + "/" + inputName;
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

    // Pedir al usuario el numero de hilos a utilizar
    int numThreads;
    cout << "Ingrese el numero de hilos a utilizar: ";
    cin >> numThreads;
    auto start = high_resolution_clock::now();
    // Convertir la imagen a escala de grises utilizando hilos
    Mat grayImg(rows, cols, CV_8UC1);

    // Vector para almacenar los hilos
    vector<thread> threads;

    // Dividir la tarea entre los hilos
    int rowsPerThread = rows / numThreads;
    int startRow = 0;
    int endRow = rowsPerThread;

    for (int i = 0; i < numThreads; i++) {
        threads.emplace_back(convertToGrayscale, ref(img), ref(grayImg), startRow, endRow);
        startRow = endRow;
        endRow = (i == numThreads - 2) ? rows : endRow + rowsPerThread;
    }

    // Esperar a que todos los hilos terminen
    for (auto& t : threads) {
        t.join();
    }

    // Mostrar la imagen original y la imagen en escala de grises
    imshow("Imagen Original", img);
    imshow("Imagen en Escala de Grises (Luminosidad)", grayImg);
    auto stop = high_resolution_clock::now();


    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;
    waitKey(0);

    // Guardar la imagen en escala de grises en el archivo de salida
    imwrite(outputPath, grayImg);

    cout << "Imagen en escala de grises (Luminosidad) guardada en: " << outputPath << endl;
    
    return 0;
}