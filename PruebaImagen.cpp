#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Ruta de la imagen
    string path = "imagenes/Zero.jpg";

    // Cargar la imagen desde el archivo
    Mat img = imread(path);

    if (img.empty()) {
        cout << "No se pudo cargar la imagen: " << path << endl;
        return 1;
    }

    // Obtener las dimensiones de la imagen
    int rows = img.rows;
    int cols = img.cols;

    // Convertir la imagen a escala de grises utilizando el método de luminosidad
    Mat grayImg(rows, cols, CV_8UC1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Vec3b pixel = img.at<Vec3b>(i, j);

            // Calcular la luminosidad
            uchar luminosity = static_cast<uchar>(0.21 * pixel[2] + 0.72 * pixel[1] + 0.07 * pixel[0]);

            // Asignar el valor de luminosidad al pixel en la imagen en escala de grises
            grayImg.at<uchar>(i, j) = luminosity;
        }
    }

    // Mostrar la imagen original y la imagen en escala de grises
    imshow("Imagen Original", img);
    imshow("Imagen en Escala de Grises (Luminosidad)", grayImg);

    waitKey(0);

    // Guardar la imagen en escala de grises en una carpeta
    string outputPath = "imagenesConvertidas/ImagenEnEscalaGris.png";
    imwrite(outputPath, grayImg);

    cout << "Imagen en escala de grises (Luminosidad) guardada en: " << outputPath << endl;

    return 0;
}