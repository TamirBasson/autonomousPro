import pyrealsense2 as rs
import numpy as np

class RSCameraManager:
    def __init__(self, width=640, height=480, fps=30):
        self.pipeline = rs.pipeline()
        self.config = rs.config()

        self.config.enable_stream(rs.stream.color, width, height, rs.format.bgr8, fps)
        self.config.enable_stream(rs.stream.depth, width, height, rs.format.z16, fps)

        self.align = rs.align(rs.stream.color)
        self.pipeline.start(self.config)

    def get_aligned_frames(self):
        frames = self.pipeline.wait_for_frames()
        return self.align.process(frames)

    def get_rgb_image(self):
        frames = self.get_aligned_frames()
        color_frame = frames.get_color_frame()
        if not color_frame:
            return None
        return np.asanyarray(color_frame.get_data())

    def get_depth_in_rect(self, rect):
        frames = self.get_aligned_frames()
        depth_frame = frames.get_depth_frame()
        if not depth_frame:
            return None

        depth_image = np.asanyarray(depth_frame.get_data())
        x1, y1, x2, y2 = rect
        roi = depth_image[y1:y2, x1:x2]
        valid = roi[roi > 0]
        return int(np.mean(valid)) if valid.size > 0 else 0

    def stop(self):
        self.pipeline.stop()
