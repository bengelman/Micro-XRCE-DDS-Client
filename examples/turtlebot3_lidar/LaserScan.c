// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file LaserScan.c
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#include "LaserScan.h"

#include <ucdr/microcdr.h>
#include <string.h>

bool LaserScan_serialize_topic(ucdrBuffer* writer, const LaserScan* topic)
{
    (void) Header_serialize_topic(writer, &topic->header);
    (void) ucdr_serialize_float(writer, topic->angle_min);
    (void) ucdr_serialize_float(writer, topic->angle_max);
    (void) ucdr_serialize_float(writer, topic->angle_increment);
    (void) ucdr_serialize_float(writer, topic->time_increment);
    (void) ucdr_serialize_float(writer, topic->scan_time);
    (void) ucdr_serialize_float(writer, topic->range_min);
    (void) ucdr_serialize_float(writer, topic->range_max);
    (void) ucdr_serialize_sequence_float(writer, topic->ranges, topic->ranges_size);
    (void) ucdr_serialize_sequence_float(writer, topic->intensities, topic->intensities_size);
    return !writer->error;
}

bool LaserScan_deserialize_topic(ucdrBuffer* reader, LaserScan* topic)
{
    (void) Header_deserialize_topic(reader, &topic->header);
    (void) ucdr_deserialize_float(reader, &topic->angle_min);
    (void) ucdr_deserialize_float(reader, &topic->angle_max);
    (void) ucdr_deserialize_float(reader, &topic->angle_increment);
    (void) ucdr_deserialize_float(reader, &topic->time_increment);
    (void) ucdr_deserialize_float(reader, &topic->scan_time);
    (void) ucdr_deserialize_float(reader, &topic->range_min);
    (void) ucdr_deserialize_float(reader, &topic->range_max);
    (void) ucdr_deserialize_sequence_float(reader, topic->ranges, sizeof(topic->ranges)/sizeof(float), &topic->ranges_size);
    (void) ucdr_deserialize_sequence_float(reader, topic->intensities, sizeof(topic->intensities)/sizeof(float), &topic->intensities_size);

    return !reader->error;
}

uint32_t LaserScan_size_of_topic(const LaserScan* topic, uint32_t size)
{
    uint32_t previousSize = size;

    size += Header_size_of_topic(&topic->header, size);
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + (topic->ranges_size * 4);

    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + (topic->intensities_size * 4);

    return size - previousSize;
}
