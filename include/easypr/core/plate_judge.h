#ifndef __PLATE_JUDGE_H__
#define __PLATE_JUDGE_H__

#include "easypr/core/plate.h"
#include "easypr/core/feature.h"
#include "easypr/core/core_func.h"

namespace easypr {

class PlateJudge {
 public:
  static PlateJudge* instance();
   
   //! 对多幅车牌进行SVM判断
  int plateJudge(const std::vector<CPlate>&, std::vector<CPlate>&);

  //! 车牌判断
  int plateJudge(const std::vector<Mat>&, std::vector<Mat>&);

  //! 车牌判断（一副图像）
  int plateJudge(const Mat& inMat, int& result);

  //! 直方图均衡
  Mat histeq(Mat);

 private:
  PlateJudge();

  static PlateJudge* instance_;

  cv::Ptr<ml::SVM> svm_;

};

}

#endif