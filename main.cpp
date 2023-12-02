#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // Especifica la ruta completa de la imagen
    cv::Mat imagen = cv::imread("/ruta/completa/a/imagen.jpg");

    // Verifica si la imagen se cargó correctamente
    if (imagen.empty()) {
        std::cerr << "Error al cargar la imagen" << std::endl;
        return -1;
    }

    // Muestra la imagen en una ventana
    cv::imshow("Imagen", imagen);

    // Espera hasta que se presiona una tecla
    cv::waitKey(0);

    return 0;
}

