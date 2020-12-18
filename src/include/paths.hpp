#ifndef PATHS_HPP
#define PATHS_HPP

#include <filesystem>

namespace paths {
const std::filesystem::path config_path = "/etc/security/howdy/howdy.ini";

const std::filesystem::path _data_dir = "/usr/share/howdy/dlib-data/";
const std::filesystem::path shape_predictor_landmarks_path =
    _data_dir / "shape_predictor_5_face_landmarks.dat";
const std::filesystem::path face_recognition_model_path =
    _data_dir / "dlib_face_recognition_resnet_model_v1.dat";

const std::filesystem::path models_dir = "/etc/security/howdy/models/";
} // namespace paths

#endif // PATHS_HPP
