/*
 *      Copyright (c) 2015 Garrett Brown
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
 *  deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *      The above copyright notice and this permission notice shall be included
 *      in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *  IN THE SOFTWARE.
 */
#pragma once

//#include "image_transport/image_transport.h"
#include "theora_image_transport/Packet.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/subscriber.h"
#include "sensor_msgs/Image.h"

class StreamingNode
{
public:
  StreamingNode(void);
  ~StreamingNode(void) { Deinitialize(); }

  bool Initialize(void);
  void Deinitialize(void) { }

  bool OK(void) const { return m_node.ok(); }

  void ReceivePacket(const theora_image_transport::PacketConstPtr& packet);
  void PublishJoystick(void);

private:
  ros::NodeHandle                 m_node;
  //image_transport::ImageTransport m_transport;
  ros::Publisher                  m_publisher;
  //image_transport::Subscriber     m_subscriber;
  ros::Subscriber                 m_subscriber;
};
