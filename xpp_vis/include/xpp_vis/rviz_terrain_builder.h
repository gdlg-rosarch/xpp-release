/******************************************************************************
Copyright (c) 2017, Alexander W. Winkler, ETH Zurich. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of ETH ZURICH nor the names of its contributors may be
      used to endorse or promote products derived from this software without
      specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ETH ZURICH BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#ifndef XPP_RVIZ_TERRAIN_BUILDER_H_
#define XPP_RVIZ_TERRAIN_BUILDER_H_

#include <string>

#include <Eigen/Dense>

#include <visualization_msgs/MarkerArray.h>
#include <geometry_msgs/PoseStamped.h>

#include <xpp_msgs/StateLin3d.h>


namespace xpp {

/**
 * @brief  Constructs RVIZ markers that show different terrains.
 *
 * This class shows simple terrains (flat, sloped, stairs, ...) through
 * basic RVIZ shapes.
 */
class RvizTerrainBuilder {
public:
  using Marker       = visualization_msgs::Marker;
  using MarkerArray  = visualization_msgs::MarkerArray;
  using Vector3d     = Eigen::Vector3d;
  using Quat         = Eigen::Quaterniond;

  /**
   * @brief  Creates a default terrain builder object.
   */
  RvizTerrainBuilder () {};
  virtual ~RvizTerrainBuilder () {};


  /**
   * @brief  Constructs the rviz markers for a specific terrain.
   * @param  terrain_id  The identifier for a specific terrain.
   */
  MarkerArray BuildTerrain(int terrain_id);

  /**
   * @brief Visualizes a 6D pose in rviz
   * @param pos  The linear position expressed in world frame (W).
   * @param orientation  In Euler angles (ZYX-convention).
   */
  geometry_msgs::PoseStamped BuildPose(const geometry_msgs::Point pos_W,
                                       xpp_msgs::StateLin3d orientation) const;

private:
  MarkerArray BuildTerrainFlat()      const;
  MarkerArray BuildTerrainBlock()     const;
  MarkerArray BuildTerrainStairs()    const;
  MarkerArray BuildTerrainGap()       const;
  MarkerArray BuildTerrainSlope()     const;
  MarkerArray BuildTerrainChimney()   const;
  MarkerArray BuildTerrainChimneyLR() const;

  Marker BuildTerrainBlock(const Vector3d& pos,
                           const Vector3d& edge_length,
                           const Quat& ori = Quat::Identity()) const;

  const double eps_ = 0.02;           // for lowering of terrain.
  const int terrain_ids_start_ = 50;  // to not overwrite other RVIZ markers.
  std::string rviz_frame_ = "world";  // the name of the frame set in RVIZ.
};

} /* namespace xpp */

#endif /* XPP_RVIZ_TERRAIN_BUILDER_H_ */
