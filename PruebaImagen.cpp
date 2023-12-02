#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

<<<<<<< HEAD
int main()
{
=======
int main() {
>>>>>>> 450bbcce3d09fc6f03aaee85a975f4e02b1c3407
    // Carpeta que contiene las imágenes de entrada
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

<<<<<<< HEAD
    if (img.empty())
    {
=======
    if (img.empty()) {
>>>>>>> 450bbcce3d09fc6f03aaee85a975f4e02b1c3407
        cout << "No se pudo cargar la imagen de entrada: " << inputPath << endl;
        return 1;
    }

    // Obtener las dimensiones de la imagen
    int rows = img.rows;
    int cols = img.cols;

    // Convertir la imagen a escala de grises utilizando el método de luminosidad
    Mat grayImg(rows, cols, CV_8UC1);

<<<<<<< HEAD
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
=======
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
>>>>>>> 450bbcce3d09fc6f03aaee85a975f4e02b1c3407
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
    imwrite(outputPath, grayImg);
    waitKey(0);

    // Guardar la imagen en escala de grises en el archivo de salida
<<<<<<< HEAD
=======
   
>>>>>>> 450bbcce3d09fc6f03aaee85a975f4e02b1c3407

    cout << "Imagen en escala de grises (Luminosidad) guardada en: " << outputPath << endl;

    return 0;
}