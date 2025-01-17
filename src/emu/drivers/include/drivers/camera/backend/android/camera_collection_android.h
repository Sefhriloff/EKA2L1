/*
 * Copyright (c) 2022 EKA2L1 Team.
 *
 * This file is part of EKA2L1 project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <drivers/camera/camera_collection.h>

#include <map>
#include <memory>
#include <vector>

namespace eka2l1::drivers::camera {
    class instance_android;

    class collection_android : public collection {
    private:
        friend class instance_android;

        std::map<int, instance_android*> current_reserved_;

    public:
        std::uint32_t count() const override;
        std::unique_ptr<instance> make_camera(const std::uint32_t camera_index) override;

        void handle_image_capture_delivered(int index, const void *bytes, const std::size_t size, const int error);
        bool reserved_wants_new_frame(int index);
    };
}